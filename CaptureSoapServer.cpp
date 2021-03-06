/*
**Created by Xeno Kovah of the MITRE HoneyClient Project 5/20/2008
*/

#include "CaptureSoapServer.h"
#include "soapH.h"
#include "capture.nsmap" 
#include "Visitor.h"
#include "b64.h" //nice small 3rd party lib for base64 encode/decode

//Only global so that the destructors can be used in ~CaptureSoapServer
//Didn't go in the class definition because adding soapH.h to CaptureSoapServer.h caused compile issues
//that I didn't want to deal with
struct soap soap;

std::list<struct ns__regkey> regList;
std::list<struct ns__regkey> regDeallocList;
std::list<struct ns__processFile> fileList;
std::list<struct ns__processFile> fileDeallocList;
std::list<struct ns__osProcess> procList;
std::list<struct ns__osProcess> procDeallocList;
void dealloc_events(); //For cleaning up when we're done with them

CaptureSoapServer::CaptureSoapServer(Visitor* v, RegistryMonitor * r, FileMonitor * f, ProcessMonitor * p){
	registryMonitor = r;
	fileMonitor = f;
	processMonitor = p;
	CaptureSoapServerThread = new Thread(this);
	CaptureSoapServerThread->start("CaptureSoapServer");
}

CaptureSoapServer::~CaptureSoapServer(){
	soap_destroy(&soap);
	soap_end(&soap);
	soap_done(&soap);
}

void
CaptureSoapServer::run(){

	char debug = 0;
   SOCKET m, s; // master and slave sockets

	onProcessEventConnection = processMonitor->connect_onProcessEvent(boost::bind(&CaptureSoapServer::onProcessEvent, this, _1, _2, _3, _4, _5, _6));
	onRegistryEventConnection = registryMonitor->connect_onRegistryEvent(boost::bind(&CaptureSoapServer::onRegistryEvent, this, _1, _2, _3, _4, _5));
	onFileEventConnection = fileMonitor->connect_onFileEvent(boost::bind(&CaptureSoapServer::onFileEvent, this, _1, _2, _3, _4, _5));

   //The below code is taken mostly from the gsoap standalone server example page
   soap_init(&soap);
   //TODO: change this to the desired port
   m = soap_bind(&soap, "0.0.0.0", 1234, 100);
   if (m < 0)
      soap_print_fault(&soap, stderr);
   else
   {
      if(debug) fprintf(stderr, "Socket connection successful: master socket = %d\n", m);
      for (int i = 1; ; i++)
      {
         s = soap_accept(&soap);
         if (s < 0)
         {
            soap_print_fault(&soap, stderr);
            break;
         }
         if(debug) fprintf(stderr, "%d: accepted connection from IP=%d.%d.%d.%d socket=%d\n", i,
            (soap.ip >> 24)&0xFF, (soap.ip >> 16)&0xFF, (soap.ip >> 8)&0xFF, soap.ip&0xFF, s);
         if (soap_serve(&soap) != SOAP_OK) // process RPC request
            soap_print_fault(&soap, stderr); // print error
         if(debug) fprintf(stderr, "you got served!\n");
         soap_destroy(&soap); // clean up class instances
         soap_end(&soap); // clean up everything and close socket
		 dealloc_events(); //Need to clean up any memory we malloced for events
      }
   }
   soap_done(&soap); // close master socket and detach environment
}

//From RegistryMonitor.cpp
//registry event extra.at(0) == PID
//registry event extra.at(1) == name of registry value
//registry event extra.at(2) == registry value type
//registry event extra.at(3) == registry value data (if any)
void CaptureSoapServer::onRegistryEvent (wstring registryEventType, wstring time, 
										wstring processPath, wstring registryEventPath, 
										vector<wstring> extra)
{
	char debug = 0;
	if(debug) printf("CaptureSoapServer::onRegistryEvent got an event for time = %ls, length = %d\n", time.c_str(), time.length());

	//now begins the arduous process of converting the values into char *s
	ns__regkey_t r;
	r.created_at = (char *)malloc(time.length()+1);
	sprintf(r.created_at, "%ls", time.c_str());

	r.event_type = (char *)malloc(registryEventType.length()+1);
	sprintf(r.event_type, "%ls", registryEventType.c_str());

	char * tmp = (char *)malloc(extra.at(0).length()+1);
	sprintf(tmp, "%ls", extra.at(0).c_str());
	r.pid = atoi(tmp);
	free(tmp);

	r.proc_name = (char *)malloc(processPath.length()+1);
	sprintf(r.proc_name, "%ls", processPath.c_str());

	r.name = (char *)malloc(registryEventPath.length()+1);
	sprintf(r.name, "%ls", registryEventPath.c_str());

	r.value_name = (char *)malloc(extra.at(1).length()+1);
	sprintf(r.value_name, "%ls", extra.at(1).c_str());

	r.value_type = (char *)malloc(extra.at(2).length()+1);
	sprintf(r.value_type, "%ls", extra.at(2).c_str());

	r.value = (char *)malloc(extra.at(3).length()+1);
	sprintf(r.value, "%ls", extra.at(3).c_str());
	
	if(debug){
		int * b = (int *)&r;
		for(int i = 0; i < 8; i++){
			printf("r[%d] = %#x\n", i, b[i]);
		}
	}

	regList.push_back(r);
	if(debug) printf("added one event to regList. Now there are %d elements in the list\n", regList.size());
}

//From FileMonitor.cpp
//file event extra.at(0) == PID
void CaptureSoapServer::onFileEvent(wstring fileEventType, wstring time, 
									wstring processPath, wstring fileEventPath, 
									vector<wstring> extra)
{
	char debug = 0;
	if(debug) printf("CaptureSoapServer::onFileEvent got an event for time = %ls\n", time.c_str());
	ns__processFile_t f;
	f.created_at = (char *)malloc(time.length()+1);
	sprintf(f.created_at, "%ls", time.c_str());

	f.event_type = (char *)malloc(fileEventType.length()+1);
	sprintf(f.event_type, "%ls", fileEventType.c_str());

	char * tmp = (char *)malloc(extra.at(0).length()+1);
	sprintf(tmp, "%ls", extra.at(0).c_str());
	f.pid = atoi(tmp);
	free(tmp);

	f.proc_name = (char *)malloc(processPath.length()+1);
	sprintf(f.proc_name, "%ls", processPath.c_str());

	f.name = (char *)malloc(fileEventPath.length()+1);
	sprintf(f.name, "%ls", fileEventPath.c_str());

	if(debug){
		int * b = (int *)&f;
		for(int i = 0; i < 5; i++){
			printf("f[%d] = %#x\n", i, b[i]);
		}
	}
	fileList.push_back(f);
	if(debug) printf("added one event to fileList. Now there are %d elements in the list\n", fileList.size());

}

void CaptureSoapServer::onProcessEvent(BOOLEAN created, wstring time, 
										DWORD parentProcessId, wstring parentProcess, 
										DWORD processId, wstring process)
{
	char debug = 0;
	if(debug) printf("CaptureSoapServer::onProcessEvent got an event for time = %ls\n", time.c_str());
	ns__osProcess_t p;
	p.created_at = (char *)malloc(time.length()+1);
	sprintf(p.created_at, "%ls", time.c_str());

	p.event_type = (char *)malloc(11); //11 == max length == "terminated"
	if(created){
		sprintf(p.event_type, "created");
	}
	else{
		sprintf(p.event_type, "terminated");
	}

	p.parent_pid = parentProcessId;

	p.parent_name = (char *)malloc(parentProcess.length()+1);
	sprintf(p.parent_name, "%ls", parentProcess.c_str());

	p.pid = processId;

	p.name = (char *)malloc(process.length()+1);
	sprintf(p.name, "%ls", process.c_str());

	procList.push_back(p);
	if(debug) printf("added one event to procList. Now there are %d elements in the list\n", procList.size());

}


int ns__ping(struct soap *soap, char * a, char ** result) 
{ 
   printf("%s\n", a);
   *result = "pong";

   return SOAP_OK; 
}

//Give it a url to browse to
int ns__visitURL(struct soap *soap, char * url, int &result){
	char debug = 1;
	wchar_t xURL[1024];
	wsprintf(xURL, L"%hs", url);
	//Build my own new-fangled Element to pass to Visitor:onServerEvent
    typedef boost::signal<void (Element*)> signal_serverEvent;
	Attribute att;
	att.name = L"url";
	att.value = xURL;
	Element e;
	e.name = L"visit";
	e.attributes.push_back(att);
	e.data = NULL;
	e.dataLength = 0;
	if(debug) printf("visitURL to %s\n", url);
	EventController::getInstance()->notifyListeners(&e);

	//TODO: We currently run the browser visit event as a black box.
	//In the future we will want to be able to report back about events before
	//it times out or it's cleanly done with the browse.
	//NOTE: For now, telling the browser to run is not a blocking operation.
	//The alternate way I had done it in the past (calling Visitor::onServerEvent directly IIRC)
	//was a blocking way, and might need to be brought back, both for the blocking, and for
	//being able to get richer information back

	result = 1; //No meaning. Define some meaningful return values if desired

	return SOAP_OK;
}

int ns__sendFileBase64(struct soap *soap, char * fileName, char * data, unsigned int encodedLength, unsigned int decodedLength, int &result){
	char debug = 0;
	if(debug) printf("in ns__sendFileBase64\n");

	if(debug) printf("encodedLength = %d, decodedLength = %d, data[0][1][2][3] = %c%c%c%c\n", encodedLength, decodedLength,
		data[0], data[1], data[2], data[3]);

	//Sanity check
	if(decodedLength != b64::b64_decode(data, encodedLength, NULL, NULL)){
		printf("The decode will not be correct. Exiting\n");
		return SOAP_ERR;
	}
	//Decode the data
	char * decodedData = new char[decodedLength];
	b64::b64_decode(data, encodedLength, decodedData, decodedLength);

	printf("decodedData[0][1] = %c%c\n", decodedData[0], decodedData[1]);
	//Open a file to write the decoded data to
	HANDLE myHandle = CreateFileA(fileName, (GENERIC_READ | GENERIC_WRITE), 
									NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if(myHandle == INVALID_HANDLE_VALUE){
		printf("CreateFile failed with %d\n", GetLastError());
		return SOAP_ERR;
	}

	//Write the data
	DWORD numWrote;
	BOOL b = WriteFile(myHandle, decodedData, decodedLength, &numWrote, NULL);
	if(b){
		if(debug) printf("Wrote %d bytes of data to %s\n", numWrote, fileName);
	}
	CloseHandle(myHandle);
	delete[] decodedData;

	result = 1;

	return SOAP_OK;

}

//Allows you to ask for a file and get it back in base64.
//NOTE: While I know it will be mitigated by the network architecture, features like this
//are why we should look into SOAP over SSL
int ns__receiveFileBase64(struct soap *soap, char * fileName, ns__receiveFileStruct **result){
	int debug = 0;
	
	if(debug) printf("in ns__receiveFileBase64, about to open %s\n", fileName);

	//Open the file
	HANDLE myHandle = CreateFileA(fileName, GENERIC_READ, NULL, NULL, 
									OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(myHandle == INVALID_HANDLE_VALUE){
		printf("couldn't open the file %s. Exiting\n", fileName);
		return SOAP_ERR;
	}

	//Get the size and then read it into a buffer
	unsigned int fileSize = (unsigned int)GetFileSize(myHandle, NULL);
	if(fileSize <= 0){
		printf("Error, or zero-length file\n");
		return SOAP_ERR;
	}
	char * buffer = new char[fileSize];
	memset(buffer, 0, fileSize);

	DWORD numRead = 0;
	BOOL b = ReadFile(myHandle, buffer, fileSize, &numRead,NULL);
	if(!b || numRead != fileSize){
		printf("ReadFile error\n");
		return SOAP_ERR;
	}
	else{
		if(debug) printf("Read the file successfully\n");
	}

	//base64 the file
	unsigned int encodedLength = (unsigned int)b64::b64_encode(buffer, fileSize, NULL, NULL);
	if(debug) printf("encodedLength = %d\n", encodedLength);
	//TODO: make this a soap_malloc()
	char * encodedData = new char[encodedLength];
	memset(encodedData, 0, encodedLength);
	size_t ret = b64::b64_encode(buffer, fileSize, encodedData, encodedLength);
	if(ret == 0){
		printf("size of the buffer was insufficient, or the length of the * converted buffer was longer than destLen\n");
		return SOAP_ERR;
	}

	//return the file
	*result = soap_new_ns__receiveFileStruct(soap, 1);
	(*result)->data = encodedData;
	(*result)->encodedLength = encodedLength;
	(*result)->decodedLength = fileSize;

	if(debug) printf("cleaning up\n");
	CloseHandle(myHandle);
	delete[] buffer;
	//Don't delete[] encodedData because the SOAP stuff will need to grab the data from there for sending
	//I'm just hoping that it deletes the memory and doesn't leak it
	if(debug) printf("cleaned up successfully\n");

	return SOAP_OK;
}

//After we have sent a document into the VM, we need a way to open it.
//We want to do this in a generic way, so rather than calling specific applications with the
//document as the parameter, we instead exploit the fact that as long as default handlers are 
//set for a given file type, it can be run from the command line by simply typing its name.
//Thus we run cmd.exe with the /K option and the document name as a parameter.
//From cmd.exe help: "/K      Carries out the command specified by string but remains"

//fileName = absolute or relative file name you want to open
//waitTimeMillisec = milliseconds to Sleep() for. Should be unsigned int but SOAP::Lite doesn't
// have an 'unsigned int' type by default, and I didn't want to make one. Make sure you cast it to DWORD.
int ns__openDocument(struct soap *soap, char * fileName, int waitTimeMillisec, int &result){
	int debug = 0;
	if(debug) printf("in ns__openDocument, waitTimeMillisec = %d\n", waitTimeMillisec);

	//Create the string for the parameters
	wchar_t * docName = new wchar_t[1024];
	wsprintf(docName, L"/K %hs", fileName);

	//Create a job object to bind the processes I launch to
	//This lets us get around the problem of Windows not having good ways of determining
	//parent/child relationships, so that we don't have to care, and can for all intents
	//and purposes, terminate the entire process tree starting with the cmd.exe we're launching
	HANDLE myJobObj = CreateJobObject(NULL, NULL);
	if(myJobObj == NULL){
		printf("CreateJobObject failed with error %d\n", GetLastError());
	}

	//open with cmd.exe
	STARTUPINFO myStart;
	memset(&myStart, 0, sizeof(STARTUPINFO));
	PROCESS_INFORMATION procInfo;
	BOOL b = CreateProcess(L"C:\\WINDOWS\\system32\\cmd.exe", docName, NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, 
							NULL, NULL, &myStart, &procInfo);
	if(!b){
		printf("CreateProcess failed with error %d\n", GetLastError());
		return SOAP_ERR;
	}
	
	//Add the process to the job object.
	b = AssignProcessToJobObject(myJobObj, procInfo.hProcess);
	if(!b){
		printf("AssignProcessToJobObject failed with error %d\n", GetLastError());
		return SOAP_ERR;
	}

	if(debug) printf("dwProcessId = %d, dwThreadId = %d\n", procInfo.dwProcessId, procInfo.dwThreadId);
	if(debug) printf("Sleeping for %d seconds\n", (DWORD)waitTimeMillisec/1000);
	Sleep((DWORD)waitTimeMillisec);
	if(debug) printf("\n\nDone sleeping\n\n");
	
	//TODO: Before we terminate the jobs, see if it created any events. If so, let it run, and tell the
	//HC Manager about it. The Manager should then request the information about events separately.
	//This is the sort of check we would like for browsing as well

	b = TerminateJobObject(myJobObj, 0);
	if(!b){
		printf("TerminateProcess failed with error %d\n", GetLastError());
		return SOAP_ERR;
	}
	CloseHandle(procInfo.hProcess);
	CloseHandle(procInfo.hThread);

	result = 1;
	return SOAP_OK;
}

//If maxEventsReturned == -1, then then send as many as possible.
int ns__returnRegistryEvents(struct soap *soap, int maxEventsToReturn, struct ns__dynRegArray **result){
	char debug = 1;

	struct ns__dynRegArray * dRegArray;
	//Set up a dynamic array for each of the event types
	dRegArray = soap_new_ns__dynRegArray(soap,1);
	dRegArray->__ptr = NULL;
	dRegArray->__size = regList.size();

	//Figure out how many entries we will send back
	if(maxEventsToReturn < dRegArray->__size && maxEventsToReturn != -1){
		dRegArray->__size = maxEventsToReturn;
	}
	if(debug) printf("Sending back %d registy events\n",dRegArray->__size);

	//Allocate a flat array to hold our ns__regkeys in
	//TODO: see if soap_new_ns__regkey(soap, dRegArray->__size) works
	struct ns__regkey * ns__regkeyArray = (struct ns__regkey *)soap_malloc(soap, dRegArray->__size*sizeof(struct ns__regkey));
	dRegArray->__ptr = ns__regkeyArray;

	for(unsigned int i = 0; i < dRegArray->__size; i++){
		if(debug){
			printf("i = %d\n", i);
//			printf("regList.front().time %s, %#x\n", regList.front().time, regList.front().time);
//			printf("regList.front().eventType %s, %#x\n", regList.front().eventType, regList.front().eventType);
//			printf("regList.front().procPID %d, %#x\n", regList.front().procPID, regList.front().procPID);
//			printf("regList.front().procName %s, %#x\n", regList.front().procName, regList.front().procName);
			int * b = (int *)&regList.front();
			for(int i = 0; i < 8; i++){
				printf("regEvent[%d] = %#x\n", i, b[i]);
			}
		}
		memcpy(&ns__regkeyArray[i],&regList.front(), sizeof(struct ns__regkey));
		regDeallocList.push_back(regList.front()); //Need to keep track of it to dealloc its elements later
		regList.pop_front();
	}
	*result = dRegArray;
	return SOAP_OK;
}
int ns__returnFileEvents(struct soap *soap, int maxEventsToReturn, struct ns__dynFileArray **result){
	char debug = 1;

	struct ns__dynFileArray * dFileArray;
	dFileArray = soap_new_ns__dynFileArray(soap,1);
	dFileArray->__ptr = NULL;
	dFileArray->__size = fileList.size();
	printf("SIZE= %d",dFileArray->__size);
	printf("MAX= %d",maxEventsToReturn);

	//Figure out how many entries we will send back
	if(maxEventsToReturn < dFileArray->__size && maxEventsToReturn != -1){
		dFileArray->__size = maxEventsToReturn;
	}
	if(debug) printf("Sending back %d file events\n",dFileArray->__size);

	struct ns__processFile * ns__processFileArray = (struct ns__processFile *)soap_malloc(soap, dFileArray->__size*sizeof(struct ns__processFile));
	dFileArray->__ptr = ns__processFileArray;

	for(unsigned int i = 0; i < dFileArray->__size; i++){
		memcpy(&ns__processFileArray[i],&fileList.front(), sizeof(struct ns__processFile));
		fileDeallocList.push_back(fileList.front());
		fileList.pop_front();
	}
	
	*result = dFileArray;
	return SOAP_OK;
}
int ns__returnProcessEvents(struct soap *soap, int maxEventsToReturn, struct ns__dynProcArray **result){
	char debug = 1;

	struct ns__dynProcArray * dProcArray;
	dProcArray = soap_new_ns__dynProcArray(soap,1);
	dProcArray->__ptr = NULL;
	dProcArray->__size = procList.size();

	if(maxEventsToReturn < dProcArray->__size && maxEventsToReturn != -1){
		dProcArray->__size = maxEventsToReturn;
	}
	if(debug) printf("Sending back %d process events\n",dProcArray->__size);

	struct ns__osProcess * ns__osProcessArray = (struct ns__osProcess *)soap_malloc(soap, dProcArray->__size*sizeof(struct ns__osProcess));
	dProcArray->__ptr = ns__osProcessArray;

	for(unsigned int i = 0; i < dProcArray->__size; i++){
		memcpy(&ns__osProcessArray[i],&procList.front(), sizeof(struct ns__osProcess));
		procDeallocList.push_back(procList.front());
		procList.pop_front();
	}
	
	*result = dProcArray;
	return SOAP_OK;
}
int ns__returnEvents(struct soap *soap, int maxEventsToReturn, ns__allEvents **result){
	char debug = 1;

	ns__allEvents * all = soap_new_ns__allEvents(soap, 1);
	all->regkeys = NULL;
	all->process_files = NULL;
	all->os_processes = NULL;
	if(regList.empty() || maxEventsToReturn == 0){
		printf("No registry events to send back\n");
	}
	else{
		ns__returnRegistryEvents(soap,maxEventsToReturn,&all->regkeys);
	}
	if(fileList.empty() || maxEventsToReturn == 0){
		printf("No file events to send back\n");
	}
	else{
		ns__returnFileEvents(soap,maxEventsToReturn,&all->process_files);
	}
	if(procList.empty() || maxEventsToReturn == 0){
		printf("No process events to send back\n");
	}
	else{
		ns__returnProcessEvents(soap,maxEventsToReturn,&all->os_processes);
	}

	*result = all;
	if(debug) printf("all->regkeys = %#x, all->process_files = %#x, all->os_processes = %#x\n", all->regkeys, all->process_files, all->os_processes);
	if(debug) printf("regList.size() = %d, fileList.size() = %d, procList.size() = %d\n", regList.size(), fileList.size(), procList.size());

	return SOAP_OK;
}

//Helper function to deallocate any memory in events which have already had their data sent via SOAP
void dealloc_events(){

	if(!regDeallocList.empty()){
		for(int i = 0; i < regDeallocList.size(); i++){
			free(regDeallocList.front().created_at);
			free(regDeallocList.front().event_type);
			free(regDeallocList.front().proc_name);
			free(regDeallocList.front().name);
			free(regDeallocList.front().value_name);
			free(regDeallocList.front().value_type);
			free(regDeallocList.front().value);
			regDeallocList.pop_front();
		}
	}

	if(!fileDeallocList.empty()){
		for(int i = 0; i < fileDeallocList.size(); i++){
			free(fileDeallocList.front().created_at);
			free(fileDeallocList.front().event_type);
			free(fileDeallocList.front().proc_name);
			free(fileDeallocList.front().name);
			fileDeallocList.pop_front();
		}
	}

	if(!procDeallocList.empty()){
		for(int i = 0; i < procDeallocList.size(); i++){
			free(procDeallocList.front().created_at);
			free(procDeallocList.front().event_type);
			free(procDeallocList.front().parent_name);
			free(procDeallocList.front().name);
			procDeallocList.pop_front();
		}
	}

}

//Thus far, SOAP::Lite hasn't been sending the data correctly, so we never get into this function.
//Removing the "This is a multipart message in MIME format..." from MIME::Entity's Entity.pm at least gets 
//rid of the gSOAP "No XML element" error, but then it doesn't seem to ever exit the SOAP::Lite send.
int ns__sendMIME(struct soap *soap, int magicNumber, int &result){
	printf("In ns__sendMIME\n");

	//From the gSOAP documentation example
	struct soap_multipart * attachment;
	for(attachment = soap->mime.list; attachment; attachment = attachment->next){
	   printf("MIME attachment:\n"); 
	   printf("Memory=%p\n", (*attachment).ptr); 
	   printf("Size=%ul\n", (*attachment).size); 
	   printf("Encoding=%d\n", (int)(*attachment).encoding); 
	   printf("Type=%s\n", (*attachment).type?(*attachment).type:"null"); 
	   printf("ID=%s\n", (*attachment).id?(*attachment).id:"null"); 
	   printf("Location=%s\n", (*attachment).location?(*attachment).location:"null"); 
	   printf("Description=%s\n", (*attachment).description?(*attachment).description:"null");
	}

	printf("magicNumber = %#x\n", magicNumber);
	if(magicNumber == 123){
		result = 42;
	}
	else{
		result = 0;
	}

	return SOAP_OK;
}
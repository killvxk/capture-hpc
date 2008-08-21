/* soapH.h
   Generated by gSOAP 2.7.10 from captureGSOAP.h
   Copyright(C) 2000-2008, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef soapH_H
#define soapH_H
#include "soapStub.h"
#ifndef WITH_NOIDREF

#ifdef __cplusplus
extern "C" {
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_markelement(struct soap*, const void*, int);
SOAP_FMAC3 int SOAP_FMAC4 soap_putelement(struct soap*, const void*, const char*, int, int);
SOAP_FMAC3 void *SOAP_FMAC4 soap_getelement(struct soap*, int*);

#ifdef __cplusplus
}
#endif
SOAP_FMAC3 int SOAP_FMAC4 soap_putindependent(struct soap*);
SOAP_FMAC3 int SOAP_FMAC4 soap_getindependent(struct soap*);
#endif
SOAP_FMAC3 int SOAP_FMAC4 soap_ignore_element(struct soap*);

SOAP_FMAC3 void * SOAP_FMAC4 soap_instantiate(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 int SOAP_FMAC4 soap_fdelete(struct soap_clist*);
SOAP_FMAC3 void* SOAP_FMAC4 soap_class_id_enter(struct soap*, const char*, void*, int, size_t, const char*, const char*);

#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (3)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_byte(struct soap*, char *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_byte(struct soap*, const char *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_byte(struct soap*, const char*, int, const char *, const char*);
SOAP_FMAC3 char * SOAP_FMAC4 soap_get_byte(struct soap*, char *, const char*, const char*);
SOAP_FMAC3 char * SOAP_FMAC4 soap_in_byte(struct soap*, const char*, char *, const char*);

#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_int(struct soap*, int *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_int(struct soap*, const int *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_int(struct soap*, const char*, int, const int *, const char*);
SOAP_FMAC3 int * SOAP_FMAC4 soap_get_int(struct soap*, int *, const char*, const char*);
SOAP_FMAC3 int * SOAP_FMAC4 soap_in_int(struct soap*, const char*, int *, const char*);

#ifndef SOAP_TYPE_unsignedInt
#define SOAP_TYPE_unsignedInt (8)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_unsignedInt(struct soap*, unsigned int *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_unsignedInt(struct soap*, const unsigned int *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_unsignedInt(struct soap*, const char*, int, const unsigned int *, const char*);
SOAP_FMAC3 unsigned int * SOAP_FMAC4 soap_get_unsignedInt(struct soap*, unsigned int *, const char*, const char*);
SOAP_FMAC3 unsigned int * SOAP_FMAC4 soap_in_unsignedInt(struct soap*, const char*, unsigned int *, const char*);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (37)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Fault(struct soap*, const char*, int, const struct SOAP_ENV__Fault *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_get_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_in_SOAP_ENV__Fault(struct soap*, const char*, struct SOAP_ENV__Fault *, const char*);
SOAP_FMAC5 struct SOAP_ENV__Fault * SOAP_FMAC6 soap_new_SOAP_ENV__Fault(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault*);
SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_instantiate_SOAP_ENV__Fault(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Fault(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (36)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Reason(struct soap*, const char*, int, const struct SOAP_ENV__Reason *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_get_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_in_SOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason *, const char*);
SOAP_FMAC5 struct SOAP_ENV__Reason * SOAP_FMAC6 soap_new_SOAP_ENV__Reason(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason*);
SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_instantiate_SOAP_ENV__Reason(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Reason(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (33)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Detail(struct soap*, const char*, int, const struct SOAP_ENV__Detail *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_get_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_in_SOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail *, const char*);
SOAP_FMAC5 struct SOAP_ENV__Detail * SOAP_FMAC6 soap_new_SOAP_ENV__Detail(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail*);
SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_instantiate_SOAP_ENV__Detail(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Detail(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (31)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Code(struct soap*, const char*, int, const struct SOAP_ENV__Code *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_get_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_in_SOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code *, const char*);
SOAP_FMAC5 struct SOAP_ENV__Code * SOAP_FMAC6 soap_new_SOAP_ENV__Code(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code*);
SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_instantiate_SOAP_ENV__Code(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Code(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (30)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Header(struct soap*, const char*, int, const struct SOAP_ENV__Header *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_get_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_in_SOAP_ENV__Header(struct soap*, const char*, struct SOAP_ENV__Header *, const char*);
SOAP_FMAC5 struct SOAP_ENV__Header * SOAP_FMAC6 soap_new_SOAP_ENV__Header(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header*);
SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_instantiate_SOAP_ENV__Header(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Header(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef SOAP_TYPE_ns__visit
#define SOAP_TYPE_ns__visit (29)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__visit(struct soap*, struct ns__visit *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__visit(struct soap*, const struct ns__visit *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__visit(struct soap*, const struct ns__visit *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__visit(struct soap*, const char*, int, const struct ns__visit *, const char*);
SOAP_FMAC3 struct ns__visit * SOAP_FMAC4 soap_get_ns__visit(struct soap*, struct ns__visit *, const char*, const char*);
SOAP_FMAC3 struct ns__visit * SOAP_FMAC4 soap_in_ns__visit(struct soap*, const char*, struct ns__visit *, const char*);
SOAP_FMAC5 struct ns__visit * SOAP_FMAC6 soap_new_ns__visit(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_ns__visit(struct soap*, struct ns__visit*);
SOAP_FMAC3 struct ns__visit * SOAP_FMAC4 soap_instantiate_ns__visit(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__visit(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__visitResponse
#define SOAP_TYPE_ns__visitResponse (28)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__visitResponse(struct soap*, struct ns__visitResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__visitResponse(struct soap*, const struct ns__visitResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__visitResponse(struct soap*, const struct ns__visitResponse *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__visitResponse(struct soap*, const char*, int, const struct ns__visitResponse *, const char*);
SOAP_FMAC3 struct ns__visitResponse * SOAP_FMAC4 soap_get_ns__visitResponse(struct soap*, struct ns__visitResponse *, const char*, const char*);
SOAP_FMAC3 struct ns__visitResponse * SOAP_FMAC4 soap_in_ns__visitResponse(struct soap*, const char*, struct ns__visitResponse *, const char*);
SOAP_FMAC5 struct ns__visitResponse * SOAP_FMAC6 soap_new_ns__visitResponse(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_ns__visitResponse(struct soap*, struct ns__visitResponse*);
SOAP_FMAC3 struct ns__visitResponse * SOAP_FMAC4 soap_instantiate_ns__visitResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__visitResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__ping
#define SOAP_TYPE_ns__ping (26)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__ping(struct soap*, struct ns__ping *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__ping(struct soap*, const struct ns__ping *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__ping(struct soap*, const struct ns__ping *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__ping(struct soap*, const char*, int, const struct ns__ping *, const char*);
SOAP_FMAC3 struct ns__ping * SOAP_FMAC4 soap_get_ns__ping(struct soap*, struct ns__ping *, const char*, const char*);
SOAP_FMAC3 struct ns__ping * SOAP_FMAC4 soap_in_ns__ping(struct soap*, const char*, struct ns__ping *, const char*);
SOAP_FMAC5 struct ns__ping * SOAP_FMAC6 soap_new_ns__ping(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_ns__ping(struct soap*, struct ns__ping*);
SOAP_FMAC3 struct ns__ping * SOAP_FMAC4 soap_instantiate_ns__ping(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__ping(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__pingResponse
#define SOAP_TYPE_ns__pingResponse (25)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__pingResponse(struct soap*, struct ns__pingResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__pingResponse(struct soap*, const struct ns__pingResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__pingResponse(struct soap*, const struct ns__pingResponse *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__pingResponse(struct soap*, const char*, int, const struct ns__pingResponse *, const char*);
SOAP_FMAC3 struct ns__pingResponse * SOAP_FMAC4 soap_get_ns__pingResponse(struct soap*, struct ns__pingResponse *, const char*, const char*);
SOAP_FMAC3 struct ns__pingResponse * SOAP_FMAC4 soap_in_ns__pingResponse(struct soap*, const char*, struct ns__pingResponse *, const char*);
SOAP_FMAC5 struct ns__pingResponse * SOAP_FMAC6 soap_new_ns__pingResponse(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_ns__pingResponse(struct soap*, struct ns__pingResponse*);
SOAP_FMAC3 struct ns__pingResponse * SOAP_FMAC4 soap_instantiate_ns__pingResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__pingResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__openDocument
#define SOAP_TYPE_ns__openDocument (22)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__openDocument(struct soap*, struct ns__openDocument *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__openDocument(struct soap*, const struct ns__openDocument *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__openDocument(struct soap*, const struct ns__openDocument *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__openDocument(struct soap*, const char*, int, const struct ns__openDocument *, const char*);
SOAP_FMAC3 struct ns__openDocument * SOAP_FMAC4 soap_get_ns__openDocument(struct soap*, struct ns__openDocument *, const char*, const char*);
SOAP_FMAC3 struct ns__openDocument * SOAP_FMAC4 soap_in_ns__openDocument(struct soap*, const char*, struct ns__openDocument *, const char*);
SOAP_FMAC5 struct ns__openDocument * SOAP_FMAC6 soap_new_ns__openDocument(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_ns__openDocument(struct soap*, struct ns__openDocument*);
SOAP_FMAC3 struct ns__openDocument * SOAP_FMAC4 soap_instantiate_ns__openDocument(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__openDocument(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__openDocumentResponse
#define SOAP_TYPE_ns__openDocumentResponse (21)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__openDocumentResponse(struct soap*, struct ns__openDocumentResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__openDocumentResponse(struct soap*, const struct ns__openDocumentResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__openDocumentResponse(struct soap*, const struct ns__openDocumentResponse *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__openDocumentResponse(struct soap*, const char*, int, const struct ns__openDocumentResponse *, const char*);
SOAP_FMAC3 struct ns__openDocumentResponse * SOAP_FMAC4 soap_get_ns__openDocumentResponse(struct soap*, struct ns__openDocumentResponse *, const char*, const char*);
SOAP_FMAC3 struct ns__openDocumentResponse * SOAP_FMAC4 soap_in_ns__openDocumentResponse(struct soap*, const char*, struct ns__openDocumentResponse *, const char*);
SOAP_FMAC5 struct ns__openDocumentResponse * SOAP_FMAC6 soap_new_ns__openDocumentResponse(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_ns__openDocumentResponse(struct soap*, struct ns__openDocumentResponse*);
SOAP_FMAC3 struct ns__openDocumentResponse * SOAP_FMAC4 soap_instantiate_ns__openDocumentResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__openDocumentResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__sendMIME
#define SOAP_TYPE_ns__sendMIME (19)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__sendMIME(struct soap*, struct ns__sendMIME *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__sendMIME(struct soap*, const struct ns__sendMIME *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__sendMIME(struct soap*, const struct ns__sendMIME *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__sendMIME(struct soap*, const char*, int, const struct ns__sendMIME *, const char*);
SOAP_FMAC3 struct ns__sendMIME * SOAP_FMAC4 soap_get_ns__sendMIME(struct soap*, struct ns__sendMIME *, const char*, const char*);
SOAP_FMAC3 struct ns__sendMIME * SOAP_FMAC4 soap_in_ns__sendMIME(struct soap*, const char*, struct ns__sendMIME *, const char*);
SOAP_FMAC5 struct ns__sendMIME * SOAP_FMAC6 soap_new_ns__sendMIME(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_ns__sendMIME(struct soap*, struct ns__sendMIME*);
SOAP_FMAC3 struct ns__sendMIME * SOAP_FMAC4 soap_instantiate_ns__sendMIME(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__sendMIME(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__sendMIMEResponse
#define SOAP_TYPE_ns__sendMIMEResponse (18)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__sendMIMEResponse(struct soap*, struct ns__sendMIMEResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__sendMIMEResponse(struct soap*, const struct ns__sendMIMEResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__sendMIMEResponse(struct soap*, const struct ns__sendMIMEResponse *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__sendMIMEResponse(struct soap*, const char*, int, const struct ns__sendMIMEResponse *, const char*);
SOAP_FMAC3 struct ns__sendMIMEResponse * SOAP_FMAC4 soap_get_ns__sendMIMEResponse(struct soap*, struct ns__sendMIMEResponse *, const char*, const char*);
SOAP_FMAC3 struct ns__sendMIMEResponse * SOAP_FMAC4 soap_in_ns__sendMIMEResponse(struct soap*, const char*, struct ns__sendMIMEResponse *, const char*);
SOAP_FMAC5 struct ns__sendMIMEResponse * SOAP_FMAC6 soap_new_ns__sendMIMEResponse(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_ns__sendMIMEResponse(struct soap*, struct ns__sendMIMEResponse*);
SOAP_FMAC3 struct ns__sendMIMEResponse * SOAP_FMAC4 soap_instantiate_ns__sendMIMEResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__sendMIMEResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__receiveFileBase64
#define SOAP_TYPE_ns__receiveFileBase64 (16)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__receiveFileBase64(struct soap*, struct ns__receiveFileBase64 *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__receiveFileBase64(struct soap*, const struct ns__receiveFileBase64 *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__receiveFileBase64(struct soap*, const struct ns__receiveFileBase64 *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__receiveFileBase64(struct soap*, const char*, int, const struct ns__receiveFileBase64 *, const char*);
SOAP_FMAC3 struct ns__receiveFileBase64 * SOAP_FMAC4 soap_get_ns__receiveFileBase64(struct soap*, struct ns__receiveFileBase64 *, const char*, const char*);
SOAP_FMAC3 struct ns__receiveFileBase64 * SOAP_FMAC4 soap_in_ns__receiveFileBase64(struct soap*, const char*, struct ns__receiveFileBase64 *, const char*);
SOAP_FMAC5 struct ns__receiveFileBase64 * SOAP_FMAC6 soap_new_ns__receiveFileBase64(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_ns__receiveFileBase64(struct soap*, struct ns__receiveFileBase64*);
SOAP_FMAC3 struct ns__receiveFileBase64 * SOAP_FMAC4 soap_instantiate_ns__receiveFileBase64(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__receiveFileBase64(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__sendFileBase64
#define SOAP_TYPE_ns__sendFileBase64 (13)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__sendFileBase64(struct soap*, struct ns__sendFileBase64 *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__sendFileBase64(struct soap*, const struct ns__sendFileBase64 *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__sendFileBase64(struct soap*, const struct ns__sendFileBase64 *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__sendFileBase64(struct soap*, const char*, int, const struct ns__sendFileBase64 *, const char*);
SOAP_FMAC3 struct ns__sendFileBase64 * SOAP_FMAC4 soap_get_ns__sendFileBase64(struct soap*, struct ns__sendFileBase64 *, const char*, const char*);
SOAP_FMAC3 struct ns__sendFileBase64 * SOAP_FMAC4 soap_in_ns__sendFileBase64(struct soap*, const char*, struct ns__sendFileBase64 *, const char*);
SOAP_FMAC5 struct ns__sendFileBase64 * SOAP_FMAC6 soap_new_ns__sendFileBase64(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_ns__sendFileBase64(struct soap*, struct ns__sendFileBase64*);
SOAP_FMAC3 struct ns__sendFileBase64 * SOAP_FMAC4 soap_instantiate_ns__sendFileBase64(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__sendFileBase64(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__sendFileBase64Response
#define SOAP_TYPE_ns__sendFileBase64Response (12)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__sendFileBase64Response(struct soap*, struct ns__sendFileBase64Response *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__sendFileBase64Response(struct soap*, const struct ns__sendFileBase64Response *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__sendFileBase64Response(struct soap*, const struct ns__sendFileBase64Response *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__sendFileBase64Response(struct soap*, const char*, int, const struct ns__sendFileBase64Response *, const char*);
SOAP_FMAC3 struct ns__sendFileBase64Response * SOAP_FMAC4 soap_get_ns__sendFileBase64Response(struct soap*, struct ns__sendFileBase64Response *, const char*, const char*);
SOAP_FMAC3 struct ns__sendFileBase64Response * SOAP_FMAC4 soap_in_ns__sendFileBase64Response(struct soap*, const char*, struct ns__sendFileBase64Response *, const char*);
SOAP_FMAC5 struct ns__sendFileBase64Response * SOAP_FMAC6 soap_new_ns__sendFileBase64Response(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_ns__sendFileBase64Response(struct soap*, struct ns__sendFileBase64Response*);
SOAP_FMAC3 struct ns__sendFileBase64Response * SOAP_FMAC4 soap_instantiate_ns__sendFileBase64Response(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__sendFileBase64Response(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__receiveFileStruct
#define SOAP_TYPE_ns__receiveFileStruct (9)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__receiveFileStruct(struct soap*, struct rcvS *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__receiveFileStruct(struct soap*, struct rcvS const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__receiveFileStruct(struct soap*, const struct rcvS *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__receiveFileStruct(struct soap*, const char*, int, const struct rcvS *, const char*);
SOAP_FMAC3 struct rcvS * SOAP_FMAC4 soap_get_ns__receiveFileStruct(struct soap*, struct rcvS *, const char*, const char*);
SOAP_FMAC3 struct rcvS * SOAP_FMAC4 soap_in_ns__receiveFileStruct(struct soap*, const char*, struct rcvS *, const char*);
SOAP_FMAC5 struct rcvS * SOAP_FMAC6 soap_new_ns__receiveFileStruct(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_ns__receiveFileStruct(struct soap*, struct rcvS*);
SOAP_FMAC3 struct rcvS * SOAP_FMAC4 soap_instantiate_ns__receiveFileStruct(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__receiveFileStruct(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_rcvS
#define SOAP_TYPE_rcvS (7)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_rcvS(struct soap*, struct rcvS *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_rcvS(struct soap*, const struct rcvS *);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_rcvS(struct soap*, const struct rcvS *, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_rcvS(struct soap*, const char*, int, const struct rcvS *, const char*);
SOAP_FMAC3 struct rcvS * SOAP_FMAC4 soap_get_rcvS(struct soap*, struct rcvS *, const char*, const char*);
SOAP_FMAC3 struct rcvS * SOAP_FMAC4 soap_in_rcvS(struct soap*, const char*, struct rcvS *, const char*);
SOAP_FMAC5 struct rcvS * SOAP_FMAC6 soap_new_rcvS(struct soap*, int);
SOAP_FMAC5 void SOAP_FMAC6 soap_delete_rcvS(struct soap*, struct rcvS*);
SOAP_FMAC3 struct rcvS * SOAP_FMAC4 soap_instantiate_rcvS(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_rcvS(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (39)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Reason(struct soap*, const char *, int, struct SOAP_ENV__Reason *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason **, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason **, const char*);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (38)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Detail(struct soap*, const char *, int, struct SOAP_ENV__Detail *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail **, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail **, const char*);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (32)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Code(struct soap*, const char *, int, struct SOAP_ENV__Code *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code **, const char*, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code **, const char*);

#endif

#ifndef SOAP_TYPE_PointerTostring
#define SOAP_TYPE_PointerTostring (23)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerTostring(struct soap*, char **const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerTostring(struct soap*, char **const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerTostring(struct soap*, const char *, int, char **const*, const char *);
SOAP_FMAC3 char *** SOAP_FMAC4 soap_get_PointerTostring(struct soap*, char ***, const char*, const char*);
SOAP_FMAC3 char *** SOAP_FMAC4 soap_in_PointerTostring(struct soap*, const char*, char ***, const char*);

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default__QName(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize__QName(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put__QName(struct soap*, char *const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out__QName(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char ** SOAP_FMAC4 soap_get__QName(struct soap*, char **, const char*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in__QName(struct soap*, const char*, char **, const char*);

#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (4)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_string(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_string(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_put_string(struct soap*, char *const*, const char*, const char*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_string(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char ** SOAP_FMAC4 soap_get_string(struct soap*, char **, const char*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in_string(struct soap*, const char*, char **, const char*);

#endif

/* End of soapH.h */

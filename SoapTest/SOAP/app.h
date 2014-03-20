#import <Foundation/Foundation.h>
#import "USAdditions.h"
#import <libxml/tree.h>
#import "USGlobals.h"
#import "ns1.h"


@class app_TGetTask;
@class app_TGetTaskResponse;
@class app_TTasks;
@class app_TTask;
@class app_TPerson;
@class app_TExecutor;
@class app_TDocuments;
@class app_TDocument;


@interface app_TGetTask : NSObject {
	
/* elements */
	NSString * executorLogin;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (app_TGetTask *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * executorLogin;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface app_TPerson : NSObject {
	
/* elements */
	NSString * login;
	NSString * name;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (app_TPerson *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * login;
@property (retain) NSString * name;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface app_TExecutor : NSObject {
	
/* elements */
	NSMutableArray *executor;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (app_TExecutor *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addExecutor:(app_TPerson *)toAdd;
@property (readonly) NSMutableArray * executor;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface app_TDocument : NSObject {
	
/* elements */
	NSString * contentType;
	NSString * url;
	NSString * fileName;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (app_TDocument *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * contentType;
@property (retain) NSString * url;
@property (retain) NSString * fileName;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface app_TDocuments : NSObject {
	
/* elements */
	NSMutableArray *document;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (app_TDocuments *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addDocument:(app_TDocument *)toAdd;
@property (readonly) NSMutableArray * document;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface app_TTask : NSObject {
	
/* elements */
	app_TPerson * author;
	NSDate * deadLine;
	app_TPerson * executor;
	app_TExecutor * executors;
	NSDate * resolutionDate;
	NSString * checkReportName;
	app_TPerson * controler;
	NSString * stateName;
	NSString * text;
	NSString * text1;
	NSString * text2;
	app_TDocuments * documents;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (app_TTask *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) app_TPerson * author;
@property (retain) NSDate * deadLine;
@property (retain) app_TPerson * executor;
@property (retain) app_TExecutor * executors;
@property (retain) NSDate * resolutionDate;
@property (retain) NSString * checkReportName;
@property (retain) app_TPerson * controler;
@property (retain) NSString * stateName;
@property (retain) NSString * text;
@property (retain) NSString * text1;
@property (retain) NSString * text2;
@property (retain) app_TDocuments * documents;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface app_TTasks : NSObject {
	
/* elements */
	NSMutableArray *task;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (app_TTasks *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
- (void)addTask:(app_TTask *)toAdd;
@property (readonly) NSMutableArray * task;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface app_TGetTaskResponse : NSObject {
	
/* elements */
	NSString * executorLogin;
	app_TTasks * tasks;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (app_TGetTaskResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSString * executorLogin;
@property (retain) app_TTasks * tasks;
/* attributes */
- (NSDictionary *)attributes;
@end

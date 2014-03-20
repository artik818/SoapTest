#import <Foundation/Foundation.h>
#import "USAdditions.h"
#import <libxml/tree.h>
#import "USGlobals.h"
/* Cookies handling provided by http://en.wikibooks.org/wiki/Programming:WebObjects/Web_Services/Web_Service_Provider */
#import <libxml/parser.h>
#import "xsd.h"
#import "EDOServiceSvc.h"
#import "app.h"
#import "ns1.h"
@class EDOBindingSoapBinding;


@interface EDOServiceSvc : NSObject {
	
}
+ (EDOBindingSoapBinding *)EDOBindingSoapBinding;
@end


@class EDOBindingSoapBindingResponse;
@class EDOBindingSoapBindingOperation;


@protocol EDOBindingSoapBindingResponseDelegate <NSObject>
- (void) operation:(EDOBindingSoapBindingOperation *)operation completedWithResponse:(EDOBindingSoapBindingResponse *)response;
@end


@interface EDOBindingSoapBinding : NSObject <EDOBindingSoapBindingResponseDelegate> {
	NSURL *address;
	NSTimeInterval defaultTimeout;
	NSMutableArray *cookies;
	BOOL logXMLInOut;
	BOOL synchronousOperationComplete;
	NSString *authUsername;
	NSString *authPassword;
}
@property (copy) NSURL *address;
@property (assign) BOOL logXMLInOut;
@property (assign) NSTimeInterval defaultTimeout;
@property (nonatomic, retain) NSMutableArray *cookies;
@property (nonatomic, retain) NSString *authUsername;
@property (nonatomic, retain) NSString *authPassword;
- (id)initWithAddress:(NSString *)anAddress;
- (void)sendHTTPCallUsingBody:(NSString *)body soapAction:(NSString *)soapAction forOperation:(EDOBindingSoapBindingOperation *)operation;
- (void)addCookie:(NSHTTPCookie *)toAdd;
- (EDOBindingSoapBindingResponse *)getTaskUsingGetTask:(app_TGetTask *)aGetTask ;
- (void)getTaskAsyncUsingGetTask:(app_TGetTask *)aGetTask  delegate:(id<EDOBindingSoapBindingResponseDelegate>)responseDelegate;
@end


@interface EDOBindingSoapBindingOperation : NSOperation {
	EDOBindingSoapBinding *binding;
	EDOBindingSoapBindingResponse *response;
	id<EDOBindingSoapBindingResponseDelegate> delegate;
	NSMutableData *responseData;
	NSURLConnection *urlConnection;
}
@property (retain) EDOBindingSoapBinding *binding;
@property (readonly) EDOBindingSoapBindingResponse *response;
@property (nonatomic, assign) id<EDOBindingSoapBindingResponseDelegate> delegate;
@property (nonatomic, retain) NSMutableData *responseData;
@property (nonatomic, retain) NSURLConnection *urlConnection;
- (id)initWithBinding:(EDOBindingSoapBinding *)aBinding delegate:(id<EDOBindingSoapBindingResponseDelegate>)aDelegate;
@end



@interface EDOBindingSoapBinding_getTask : EDOBindingSoapBindingOperation {
	app_TGetTask * getTask;
}
@property (retain) app_TGetTask * getTask;
- (id)initWithBinding:(EDOBindingSoapBinding *)aBinding delegate:(id<EDOBindingSoapBindingResponseDelegate>)aDelegate
	getTask:(app_TGetTask *)aGetTask;
@end


@interface EDOBindingSoapBinding_envelope : NSObject {
}
+ (EDOBindingSoapBinding_envelope *)sharedInstance;
- (NSString *)serializedFormUsingHeaderElements:(NSDictionary *)headerElements bodyElements:(NSDictionary *)bodyElements;
@end


@interface EDOBindingSoapBindingResponse : NSObject {
	NSArray *headers;
	NSArray *bodyParts;
	NSError *error;
}
@property (retain) NSArray *headers;
@property (retain) NSArray *bodyParts;
@property (retain) NSError *error;


@end

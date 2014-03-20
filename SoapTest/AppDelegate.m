//
//  AppDelegate.m
//  SoapTest
//
//  Created by Artem on 3/20/14.
//  Copyright (c) 2014 Artem. All rights reserved.
//

#import "AppDelegate.h"
#import "EDOServiceSvc.h"


@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    
//    EDOBindingSoapBinding *binding = [EDOBindingSoapBinding
    EDOBindingSoapBinding *binding = [EDOServiceSvc EDOBindingSoapBinding];
    EDOBindingSoapBindingResponse *response;
    app_TGetTask* request = [[app_TGetTask alloc] init];
    response = [binding getTaskUsingGetTask:request];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self processResponse:response];
    });
    
    return YES;
}


-(void) processResponse: (EDOBindingSoapBindingResponse*)soapResponse
{
    NSArray *responseBodyParts = soapResponse.bodyParts;
    id bodyPart;
    @try{
        bodyPart = [responseBodyParts objectAtIndex:0]; // Assuming just 1 part in response which is fine
        
    }
    @catch (NSException* exception)
    {
        UIAlertView* alert = [[UIAlertView alloc]initWithTitle:@"Server Error"message:@"Error while trying to process request"delegate:self cancelButtonTitle:@"OK"otherButtonTitles: nil];
        [alert show];
        return;
    }
    
    if ([bodyPart isKindOfClass:[SOAPFault class]]) {
        
        NSString* errorMesg = ((SOAPFault *)bodyPart).simpleFaultString;
        UIAlertView* alert = [[UIAlertView alloc]initWithTitle:@"Server Error"message:errorMesg delegate:self cancelButtonTitle:@"OK"otherButtonTitles: nil];
        [alert show];
    }
    else if([bodyPart isKindOfClass:[CurrencyConvertorSvc_ConversionRateResponseclass]]) {
        CurrencyConvertorSvc_ConversionRateResponse* rateResponse = bodyPart;
        UIAlertView* alert = [[UIAlertViewalloc]initWithTitle:@"Success!"message:[NSStringstringWithFormat:@"Currency Conversion Rate is %@",rateResponse.ConversionRateResult] delegate:selfcancelButtonTitle:@"OK"otherButtonTitles: nil];
        [alert show];
        
    }
    
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end

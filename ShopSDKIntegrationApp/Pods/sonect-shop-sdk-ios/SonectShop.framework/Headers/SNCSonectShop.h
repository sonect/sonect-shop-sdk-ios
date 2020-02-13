//
//  SNCSonectShop.h
//  SonectSDK
//
//  Created by Ivan Yanakiev on 8.01.20.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SNCConfiguration, SNCShopCredentials, UIViewController;
@class SNCConfiguration;
@protocol SNCScanCodePlugin;

@interface SNCSonectShop : NSObject

/**
 The current configuration that is passed through the presentWithCredentials: method.
 */
@property (class, nullable, readonly) SNCConfiguration *currentConfiguration;

/**
 The current credentials that are passed through the presentWithCredentials: method.
 */
@property (class, nullable, readonly) SNCShopCredentials *currentCredentials;

/**
 The plugin to be used when scanning barcodes / QR codes.
*/
@property (class, nullable) id <SNCScanCodePlugin> scanCodePlugin;

/**
 Presents the Sonect Shop View Controller on the presenting view controller, with credentials and
 configuration provided by the client.
 The presented view controller is wrapped in a navigation controller.

 @param credentials the credentials.
 @param configuration the configuration.
 @param presentingViewController a presenting view controller.
 */
+ (void)presentWithCredentials:(SNCShopCredentials *)credentials
                 configuration:(SNCConfiguration *)configuration
      presentingViewController:(UIViewController *)presentingViewController;

@end

NS_ASSUME_NONNULL_END

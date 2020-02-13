//
//  SNCShopCredentials.h
//  SonectShop
//
//  Created by Ivan Yanakiev on 5.02.20.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SNCShopCredentials : NSObject

/**
 An SDK token.
 */
@property(nonatomic, copy, readonly) NSString* sdkToken;

/**
 Creates credentials to authorize the SDK.

 @param sdkToken an sdk token.
 @return credentials.
 */
- (instancetype)initWithSdkToken:(NSString *)sdkToken;

@end

NS_ASSUME_NONNULL_END

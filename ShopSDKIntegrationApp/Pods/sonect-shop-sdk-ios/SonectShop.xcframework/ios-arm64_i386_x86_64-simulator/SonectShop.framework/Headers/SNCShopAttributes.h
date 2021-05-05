//
//  SNCShopAttributes.h
//  SonectShop
//
//  Created by Anton Iermilin on 29.04.2021.
//  Copyright © 2021 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SNCShopAttributes : NSObject
+ (instancetype)attributes;
- (instancetype)attributesByAddingData:(NSDictionary *)data;
@end

NS_ASSUME_NONNULL_END

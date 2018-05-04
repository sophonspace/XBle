//
//  XBLEFunction.h
//  XBleSDK
//
//  Created by sophonspace on 2018/4/24.
//  Copyright © 2018年 sophonspace. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XBLEFunction : NSObject

/// 是否支持密码
@property (nonatomic, assign) BOOL isSupportPassword;
/// 是否支持指纹
@property (nonatomic, assign) BOOL isSupportFingerprint;
/// 是否支持IC卡
@property (nonatomic, assign) BOOL isSupportIcCard;
/// 是否支持调节音量
@property (nonatomic, assign) BOOL isSupportSound;

@end

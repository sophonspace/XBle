//
//  XBLEFirmware.h
//  XBleSDK
//
//  Created by sophonspace on 2018/4/4.
//  Copyright © 2018年 sophonspace. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XBLEFirmware : NSObject

/// 固件更新标识（ 1:需要更新，2:需要强制更新，3:设备已进入DFU模式，必须更新后才能使用）
@property (nonatomic, assign) NSInteger upgradeType;
/// 固件更新内容
@property (nonatomic, strong) NSArray<NSString *> *upgradeContent;
/// 固件大小（单位：kb）
@property (nonatomic, strong) NSString *size;
/// 新固件版本号
@property (nonatomic, assign) NSInteger version;

@end

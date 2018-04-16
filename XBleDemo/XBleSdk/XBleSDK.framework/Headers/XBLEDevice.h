//
//  XBLEDevice.h
//  YunoSdkDemo
//
//  Created by Sole on 2018/3/7.
//  Copyright © 2018年 sole(sole.he@sophonspace.com). All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XBLEFirmware.h"

@interface XBLEDevice : NSObject

/// 设备名称
@property (nonatomic, strong) NSString *name;
/// 设备Mac地址
@property (nonatomic, strong) NSString *mac;
/// 时间戳
@property (nonatomic, assign) long timeStamp;
/// 固件版本
@property (nonatomic, assign) int version;
/// 状态（0: 关锁，2: 开锁）
@property (nonatomic, assign) int status;
/// 类型
@property (nonatomic, assign) int type;
/// 是否已被初始化（1:未初始化，>1：已被初始化）
@property (nonatomic, assign) int state;
/// 电量
@property (nonatomic, assign) int battary;
/// 记录条数
@property (nonatomic, assign) int recordCount;
/// 备用字节
@property (nonatomic, assign) int reserve;
/// 信号强度
@property (nonatomic, strong) NSNumber *RSSI;
/// 固件(如果该属性不为nil则代表需要升级，否则无需升级)
@property (nonatomic, strong) XBLEFirmware *firmware;

@end

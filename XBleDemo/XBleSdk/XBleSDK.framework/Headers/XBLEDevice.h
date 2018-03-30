//
//  XBLEDevice.h
//  YunoSdkDemo
//
//  Created by Sole on 2018/3/7.
//  Copyright © 2018年 sole(sole.he@sophonspace.com). All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XBLEDevice : NSObject

/// 设备名称
@property (nonatomic, strong) NSString *name;
/// 设备Mac地址
@property (nonatomic, strong) NSString *mac;
/// 时间戳
@property (nonatomic, assign) long timeStamp;
/// 设备类型(需要定义)
@property (nonatomic, assign) int type;
/// 固件版本
@property (nonatomic, assign) int version;
/// 是否初始化(1: 未初始化，2: 已初始化, 3: 已初始化，且有报警信息)
@property (nonatomic, assign) int state;
/// 状态（0: 关锁，1: 开锁）
@property (nonatomic, assign) int status;
/// 电量
@property (nonatomic, assign) int battary;
/// 记录条数
@property (nonatomic, assign) int recordCount;
/// 加密类型(1: 单机版，2: 自用版，3: ID2版)
@property (nonatomic, assign) int secuType;
/// 备用字节
@property (nonatomic, assign) int reserve;
/// 更新时间(内部使用，将来去掉)
@property (nonatomic, assign) long updateTime;
/// 信号强度
@property (nonatomic, strong) NSNumber *RSSI;

@end

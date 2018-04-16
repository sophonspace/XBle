//
//  XBLELockUtils.h
//  XBleSDK
//
//  Created by sophonspace on 2018/4/2.
//  Copyright © 2018年 sole(solehe@scsocool.com). All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XBLEUtils.h"

@protocol XBLELockDelagate;

@interface XBLELockUtils : NSObject

/**
 设置锁的delegate
 */
+ (void)setLockDelegate:(id<XBLELockDelagate>)delegate;

/**
 断开指定设备连接
 
 @param mac 设备Mac地址
 */
+ (void)disconnect:(NSString *)mac;

/**
 连接指定设备（连接+认证）
 
 @param mac 设备的Mac地址
 @param result 连接状态回调
 */
+ (void)connect:(NSString *)mac result:(void(^)(XBConnectState state))result;

/**
 初始化设备
 
 @param result 命令执行结果回调
 @param mac 设备Mac地址
 */
+ (void)initialize:(void(^)(XBCmdResultCode code))result mac:(NSString *)mac;


/**
 设置设备状态
 
 @param status 目标状态
 @param result 命令执行结果回调
 @param mac 设备Mac地址
 */
+ (void)setStatus:(int)status result:(void(^)(XBCmdResultCode code))result mac:(NSString *)mac;


/**
 获取设备状态
 
 @see 结果需在 【XBLEDeviceDelagate】【- (void)device:(NSString *)mac statusChanged:(int)status】获取
 
 @param result 命令执行结果回调
 @param mac 设备Mac地址
 */
+ (void)getStatus:(void(^)(XBCmdResultCode code))result mac:(NSString *)mac;


/**
 设置提示音大小(1~100)
 
 @param volume 音量大小
 @param result 命令执行结果回调
 @param mac 设备Mac地址
 */
+ (void)setVolume:(int)volume result:(void(^)(XBCmdResultCode code))result mac:(NSString *)mac;


/**
 获取提示音大小
 
 @param result 命令执行结果回调
 @param mac 设备Mac地址
 */
+ (void)getVolume:(void(^)(XBCmdResultCode code, int value))result mac:(NSString *)mac;


/**
 设置延迟关闭时间(5~20s)
 
 @param delay 延迟时间
 @param result 执行结果回调
 @param mac 设备Mac地址
 */
+ (void)setDelay:(int)delay result:(void(^)(XBCmdResultCode code))result mac:(NSString *)mac;


/**
 获取延迟关闭时间
 
 @param result 执行结果回调
 @param mac 设备Mac地址
 */
+ (void)getDelay:(void(^)(XBCmdResultCode code, int value))result mac:(NSString *)mac;


/**
 设置永久密码
 
 @param password 密码（6~10位数字）
 @param result 命令执行结果
 @param mac 设备Mac地址
 */
+ (void)setPassword:(NSString *)password result:(void(^)(XBCmdResultCode code))result mac:(NSString *)mac;


/**
 获取临时密

 @param type 设备类型
 @param result 命令执行结果
 @param mac 设备Mac地址
 */
+ (void)getTempPassword:(int)type result:(void(^)(XBCmdResultCode code, NSString *password))result mac:(NSString *)mac;


/**
 获取操作记录
 
 @param result 执行结果回调
 @param mac 设备Mac地址
 */
+ (void)getRecord:(void(^)(XBCmdResultCode code))result mac:(NSString *)mac;


/**
 添加指纹
 
 @param result 执行结果回调
 @param mac 设备Mac地址
 */
+ (void)addFingerPrint:(void(^)(XBCmdResultCode code, int step, int number))result mac:(NSString *)mac;


/**
 删除指纹
 
 @param number 指纹编号
 @param result 执行结果回调
 @param mac 设备Mac地址
 */
+ (void)delFingerPrint:(int)number result:(void(^)(XBCmdResultCode code))result mac:(NSString *)mac;


/**
 添加IC卡
 
 @param result 执行结果回调
 @param mac 设备Mac地址
 */
+ (void)addIcCard:(void(^)(int code, uint number))result mac:(NSString *)mac;


/**
 删除IC卡
 
 @param number IC卡序号
 @param result 执行结果回调
 @param mac 设备Mac地址
 */
+ (void)delIcCard:(uint)number result:(void(^)(int code))result mac:(NSString *)mac;


/**
 同步指纹
 
 @param idList 有效指纹列表
 @param result 执行结果回调
 @param mac 设备Mac地址
 */
+ (void)synFingerPrint:(NSArray<NSNumber *> *)idList result:(void(^)(XBCmdResultCode code))result mac:(NSString *)mac;


/**
 恢复出厂设置

 @param result 执行结果回调
 @param mac 设备Mac地址
 */
+ (void)resetFactory:(void(^)(XBCmdResultCode code))result mac:(NSString *)mac;


/**
 开始固件升级

 @param mac 设备Mac地址
 */
+ (void)upgrade:(NSString *)mac result:(void(^)(BOOL success, NSInteger progress))result;



@end


/**
 设备相关协议
 */
@protocol XBLELockDelagate <NSObject>

@optional

/**
 设备状态变化回调(开关状态)
 
 @param mac 设备Mac地址
 @param status 设备当前状态
 */
- (void)device:(NSString *)mac statusChanged:(int)status;


/**
 操作记录更新
 
 @param mac 设备Mac地址
 @param records 记录列表
 */
- (void)device:(NSString *)mac record:(NSArray<XBLERecord *> *)records;


@end


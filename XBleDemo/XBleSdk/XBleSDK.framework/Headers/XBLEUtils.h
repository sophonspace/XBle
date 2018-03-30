//
//  XBLEUtils.h
//  YunoSdkDemo
//
//  Created by Sole on 2018/3/7.
//  Copyright © 2018年 sole(sole.he@sophonspace.com). All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XBLEDevice.h"
#import "XBLERecord.h"

typedef NS_ENUM(NSInteger, XBLEState) {
    XBLEStateUnknown = 0,   //未知
    XBLEStateResetting,     //重置中
    XBLEStateUnsupported,   //不支持
    XBLEStateUnauthorized,  //没有权限
    XBLEStatePoweredOff,    //关闭
    XBLEStatePoweredOn,     //开启
};

typedef NS_ENUM(NSInteger, XBConnectState) {
    /// 断开连接
    XBConnectStateDisconnected = 0,
    /// 正在连接
    XBConnectStateConnecting = 1,
    /// 已连接
    XBConnectStateConnected = 3
};

typedef NS_ENUM(NSInteger, XBCmdResultCode) {
    XBCmdResultCodeDisconnected = -4,  //蓝牙断开连接
    XBCmdResultCodeExecTimeout = -3, //命令执行超时
    XBCmdResultCodeDataError = -2,  //数据格式错误
    XBCmdResultCodeNotExec = -1,  //命令未被执行
    XBCmdResultCodeSuccess = 0  //成功
};

/**
 设备相关协议
 */
@protocol XBLEUtilsDelagate;


/**
 蓝牙类（对外）
 */
@interface XBLEUtils : NSObject


/// 设备相关代理
@property (nonatomic, weak) id<XBLEUtilsDelagate> delegate;


/**
 单例方法
 */
+ (instancetype)share;


/**
 初始化方法(SDK)
 */
- (void)setAppKey:(NSString *)key appSecurety:(NSString *)securety;


/**
 扫描蓝牙设备

 @param duration 扫描持续时间
 @param result 扫描结果回调
 @param finished 扫描结束回调
 @return 调用扫描是否成功
 */
- (BOOL)scan:(float)duration result:(void(^)(XBLEDevice *device))result compelete:(void(^)(BOOL timeout))finished;


/**
 停止扫描
 */
- (void)stopScan;


/**
 连接指定设备（普通连接）

 @param mac 设备的Mac地址
 @param result 连接状态回调
 @return 函数调用结果
 */
- (BOOL)connect:(NSString *)mac result:(void(^)(XBConnectState state))result;


/**
 断开指定设备连接

 @param mac 设备Mac地址
 @return 函数调用结果
 */
- (BOOL)disconnect:(NSString *)mac;


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
 同步指纹

 @param idList 有效指纹列表
 @param result 执行结果回调
 @param mac 设备Mac地址
 */
+ (void)synFingerPrint:(NSArray<NSNumber *> *)idList result:(void(^)(XBCmdResultCode code))result mac:(NSString *)mac;


@end



/**
 设备相关协议
 */
@protocol XBLEUtilsDelagate <NSObject>

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


/**
 系统蓝牙状态变化
 
 @param state 当前状态
 */
- (void)systemBleStateChanged:(XBLEState)state;


@end


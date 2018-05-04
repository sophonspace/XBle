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
#import "XBLEFunction.h"

// 是否支持密码
#define IsSupportPassword(type)     [[XBLEUtils share] functionWithType:type].isSupportPassword
// 是否支持指纹
#define IsSupportFingerprint(type)  [[XBLEUtils share] functionWithType:type].isSupportFingerprint
// 是否支持IC卡
#define IsSupportIcCard(type)       [[XBLEUtils share] functionWithType:type].isSupportIcCard
// 是否支持音量调节
#define IsSupportSound(type)        [[XBLEUtils share] functionWithType:type].isSupportSound


/// 系统蓝牙状态
typedef NS_ENUM(NSInteger, XBLEState) {
    XBLEStateUnknown = 0,   //未知
    XBLEStateResetting,     //重置中
    XBLEStateUnsupported,   //不支持
    XBLEStateUnauthorized,  //没有权限
    XBLEStatePoweredOff,    //关闭
    XBLEStatePoweredOn,     //开启
};

/// 设备连接状态
typedef NS_ENUM(NSInteger, XBConnectState) {
    /// 断开连接
    XBConnectStateDisconnected = 0,
    /// 正在连接
    XBConnectStateConnecting = 1,
    /// 已连接
    XBConnectStateConnected = 3,
    /// 连接出错
    XBConnectStateError = 4
};

/// 运行环境
typedef NS_ENUM(NSInteger, XBConfigEnv) {
    XBConfigEnvSandbox,     //测试环境
    XBConfigEnvProduction   //生产环境
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
 是否开启日志

 @param flag YES/NO
 */
- (void)openLog:(BOOL)flag;


/**
 初始化方法(SDK)

 @param key 厂商唯一码
 @param securety 厂商密钥
 @param env 当前环境
 */
- (void)initWithAppKey:(NSString *)key appSecurety:(NSString *)securety env:(XBConfigEnv)env;


/**
 登陆

 @param token 厂商自定义用户Token
 @param result 登陆结果回调
 */
- (void)loginWithCustomToken:(NSString *)token result:(void(^)(XBCmdResultCode code))result;


/**
 获取系统蓝牙状态

 @see XBLEState
 @return 当前状态
 */
- (XBLEState)systemBleState;


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
 获取设备连接状态

 @param mac 设备mac地址
 @return 当前连接状态
 */
- (XBConnectState)state:(NSString *)mac;


/**
 获取指定设备

 @param mac 设备Mac地址
 @return 设备
 */
- (XBLEDevice *)device:(NSString *)mac;


/**
 获取指定类型的设备支持的功能

 @param type 设备类型
 @return 功能集合
 */
- (XBLEFunction *)functionWithType:(NSInteger)type;

@end



/**
 设备相关协议
 */
@protocol XBLEUtilsDelagate <NSObject>


@optional

/**
 系统蓝牙状态变化
 
 @param state 当前状态
 */
- (void)systemBleStateChanged:(XBLEState)state;


@end


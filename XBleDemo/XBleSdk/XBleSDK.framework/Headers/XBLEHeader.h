//
//  XBLEHeader.h
//  YunoSdkDemo
//
//  Created by sophonspace on 2018/4/21.
//  Copyright © 2018年 sophonspace. All rights reserved.
//

#ifndef XBLEHeader_h
#define XBLEHeader_h


/**
 错误码
 */
typedef NS_ENUM(NSInteger, XBCmdResultCode) {
    
    XBCmdResultCodeIdNotExist       = -10,  //注册码不存在
    
    XBCmdResultCodeDisconnected     = -4,   //蓝牙断开连接
    XBCmdResultCodeExecTimeout      = -3,   //命令执行超时
    XBCmdResultCodeDataError        = -2,   //数据格式错误
    XBCmdResultCodeNotExec          = -1,   //命令未被执行
    
    XBCmdResultCodeSuccess          = 0x00, //命令执行成功
    
    XBCmdResultCodeFailed           = 0x01, //命令执行失败
    XBCmdResultCodeDecryptError     = 0x02, //命令解密错误
    XBCmdResultCodeCheckSumError    = 0x03, //命令校验错误
    XBCmdResultCodeTypeError        = 0x04, //命令类型错误
    XBCmdResultCodeValueError       = 0x05, //命令值错误
    XBCmdResultCodeLenError         = 0x06, //命令长度错误
    XBCmdResultCodeRepeatInit       = 0x07, //重复初始化
    XBCmdResultCodeNotInit          = 0x08, //设备未初始化
    XBCmdResultCodeNotAuth          = 0x09, //连接未认证
    XBCmdResultCodeBusying          = 0x0A, //设备忙
    XBCmdResultCodeAuthIdFailed     = 0x0B, //ID认证失败
    XBCmdResultCodeAuthUtcFailed    = 0x0C, //UTC认证失败
    XBCmdResultCodeRadomError       = 0x0D, //验证随机数出错
    XBCmdResultCodeNoRespone        = 0x2F, //操作无响应
    
    XBCmdResultCodeFPExist          = 0x30, //指纹已存在
    XBCmdResultCodeFPAddTimeout     = 0x31, //添加指纹超时
    XBCmdResultCodeFPMaxCount       = 0x32, //指纹个数已满
    XBCmdResultCodeFPNoDetected     = 0x33, //未检测到指纹
    XBCmdResultCodeFPNotExist       = 0x34, //指纹不存在
    XBCmdResultCodeFPBusying        = 0x35, //指纹忙
    XBCmdResultCodeFPUnkownError    = 0x3F, //指纹发生未知错误
    
    XBCmdResultCodeICUnrecognized   = 0x50, //无法识别IC卡
    XBCmdResultCodeICAddTimeout     = 0x51, //添加IC卡超时
    XBCmdResultCodeICAddExist       = 0x52, //IC卡已存在
    XBCmdResultCodeICMaxCount       = 0x53, //IC卡数量已满
    XBCmdResultCodeICNotExist       = 0x54, //IC卡不存在
    XBCmdResultCodeICUnkownError    = 0x5F, //IC卡发生未知错误
    
    XBCmdResultCodeID2DecryptError  = 0x60, //ID2解密错误
    
    XBCmdResultCodeNetUnkownError           = 500, //未知网络错误
    XBCmdResultCodeNetGetUuidError          = 501, //获取设备UUID错误
    XBCmdResultCodeNetDecryptError          = 503, //解密出错
    XBCmdResultCodeNetUpdateSecurityError   = 504, //更新密钥出错
    XBCmdResultCodeNetGetSecurityError      = 505, //获取密钥数据出错
    XBCmdResultCodeNetGetAuthCodeError      = 506, //获取认证码出错
    XBCmdResultCodeNetNotAuth               = 507, //没有权限
    XBCmdResultCodeNetGetDeviceError        = 508, //获取设备失败
    XBCmdResultCodeNetUpdateFirmwareError   = 509, //更新固件失败
    XBCmdResultCodeNetGetFirmwareInfoError  = 510, //获取固件更新信息失败
    XBCmdResultCodeNetUploadId2Error        = 511, //上传ID2密钥出错
    XBCmdResultCodeNetGetCommandError       = 512, //获取命令出错
    XBCmdResultCodeNetGetTmpPasswordError   = 513, //生成临时密码失败
    
    XBCmdResultCodeNetAuthError             = 1001, //厂商权限认证出错
    XBCmdResultCodeNetSdkError1             = 1002, //SDK内部错误1
    XBCmdResultCodeNetSdkError2             = 1003, //SDK内部错误2
    XBCmdResultCodeNetSdkExpire             = 1004, //厂商权限认证已失效
    XBCmdResultCodeNetAuthMaxCount          = 1005, //认证次数太多
    XBCmdResultCodeNetDataError             = 1006, //数据出错
    XBCmdResultCodeNetAuthParamError        = 1007, //认证参数错误
    XBCmdResultCodeNetApiAuthError          = 1008, //认证出错
};

#endif /* XBLEHeader_h */

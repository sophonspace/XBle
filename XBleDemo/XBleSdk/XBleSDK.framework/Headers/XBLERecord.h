//
//  XBLERecord.h
//  XBleSDK
//
//  Created by Sole on 2018/3/19.
//  Copyright © 2018年 sole(sole.he@sophonspace.com). All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XBLERecord : NSObject

/// 操作类型
@property (nonatomic, assign) int type;
/// 编号
@property (nonatomic, assign) int number;
/// 操作时间
@property (nonatomic, assign) int time;

@end

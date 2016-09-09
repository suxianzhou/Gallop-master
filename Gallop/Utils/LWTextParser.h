/*
 https://github.com/waynezxcv/Gallop

 Copyright (c) 2016 waynezxcv <liuweiself@126.com>

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */


#import <Foundation/Foundation.h>
#import "LWTextStorage.h"

@interface LWTextParser : NSObject


/**
*  解析表情替代为相应的图片
*  格式：text：@“hello,world~![微笑]”  ----> @"hello，world~！（[UIImage imageNamed：@“[微笑]”]）"
*  @param textStorage 需要解析的LWTextStorage对象
*/
+ (void)parseEmojiWithTextStorage:(LWTextStorage *)textStorage;


/**
 *  解析HTTP(s):// 并添加链接
 *
 *  @param textStorage   需要解析的LWTextStorage对象
 *  @param linkColor     链接文本颜色
 *  @param higlightColor 链接点击时高亮颜色
 */
+ (void)parseHttpURLWithTextStorage:(LWTextStorage *)textStorage
                          linkColor:(UIColor *)linkColor
                     highlightColor:(UIColor *)higlightColor;


/**
 *  解析 @用户 并添加链接
 *
 *  @param textStorage   需要解析的LWTextStorage对象
 *  @param linkColor     链接文本颜色
 *  @param higlightColor 链接点击时高亮颜色
 */
+ (void)parseAccountWithTextStorage:(LWTextStorage *)textStorage
                          linkColor:(UIColor *)linkColor
                     highlightColor:(UIColor *)higlightColor;


/**
 *  解析 #主题# 并添加链接
 *
 *  @param textStorage   需要解析的LWTextStorage对象
 *  @param linkColor     链接文本颜色
 *  @param higlightColor 链接点击时高亮颜色
 */
+ (void)parseTopicWithLWTextStorage:(LWTextStorage *)textStorage
                          linkColor:(UIColor *)linkColor
                     highlightColor:(UIColor *)higlightColor;
@end

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
#import <UIKit/UIKit.h>
#import "SDWebImageManager.h"



@interface CALayer(WebCacheOperation)

/**
 *  通过Key给CALayer对象设置下载的NSOperation对象
 *
 *  @param operation NSOperation对象
 *  @param key       NSOperation对象对应的Key
 */
- (void)sd_setImageLoadOperation:(id)operation forKey:(NSString *)key;


/**
 *  通过Key来取消这个CALayer对象上的NSOperation
 *
 *  @param key NSOperation对象对应的Key
 */
- (void)sd_cancelImageLoadOperationWithKey:(NSString *)key;


/**
 *  通过Key来移除这个CALayer对象上的NSOperation
 *
 *  @param key NSOperation对象对应的Key
 */
- (void)sd_removeImageLoadOperationWithKey:(NSString *)key;


@end

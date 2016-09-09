
[![License MIT](https://img.shields.io/badge/license-MIT-green.svg?style=flat)](https://github.com/waynezxcv/LWAsyncDisplayView/blob/master/LICENSE)&nbsp;


# Gallop v0.3.5

# About Gallop

Gallop是一个功能强大、性能优秀的异步绘制、图文混排框架。你只需要使用框架中抽象的LWTextStorage(相当于UIKit中的UILabel)、LWImageStorage（相当于UIKit中的UIIamgeView）模型来方便、快速地构建图文混排界面，Gallop将为你通过各种优化手段，来确保你的应用的流畅性。

## Features

主要用于解决以下需求：


* 滚动列表的性能优化,能在实现复杂的图文混排界面时，仍然保持一个相当优秀的滚动性能（FPS基本保持在60）。**项目内有使用Gallop构建的微信朋友圈Demo**
* 实现图文混排界面，比如在文本中添加表情，对文字添加点击链接。
* 简便地实现对网络图片和本地图片的圆角和模糊处理等，并能提供缓存，无需重复处理，优化性能。
* 方便的解析HTML渲染生成原生iOS页面。**项目内有使用Gallop构建的知乎日报Demo**


**滚动性能请使用真机调试查看效果**

## Demo Snapshot

![](https://github.com/waynezxcv/Gallop/raw/master/pics/1.PNG)
![](https://github.com/waynezxcv/Gallop/raw/master/pics/2.png)


***



# Modifications

v0.3.5

LWImageStorage 新增一个属性isBlur。本地图片时，将在子线程进行模糊处理；当网络图片时，将在子线程进行模糊处理并直接缓存模糊的版本。详见Demo。

v0.3.4

* 支持CoreData来缓存布局模型


v0.3.3

* 更改了集成方式，解决了与SDWebImage部分文件冲突的问题。

v0.3.2
* 现在，设置了圆角半径的网络图片将额外缓存一份，解决了内存消耗过大的问题。

v0.3.1
* 解析HTML渲染生成原生iOS页面时，图片可以按照原图比例自适应高度了。

v0.3.0 
* 增加了解析HTML渲染生成原生iOS页面的功能。

v0.2.5
* 对图片加载进行了优化。

v0.2.4
* 增加了TransactionGroup，LWTransaction，CALayer+LWTransaction。

v0.2.3 
* 文字添加了描边绘制模式。

v0.2.2 
* 增加了一个方法 


```
- (void)lw_addLinkForWholeTextStorageWithData:(id)data linkColor:(UIColor *)linkColor highLightColor:(UIColor *)highLightColor;

```


废弃了方法

```
- (id)initWithFrame:(CGRect)frame maxImageStorageCount:(NSInteger)maxCount;

```

现在，LWAsyncDisplayView内部将自动维护一个复用池，可以为LWStorage设置一个NSString*类型的Identifier，
来复用内部的相关UIView,简化API。

* 修复了对文字添加链接重叠而发生冲突的bug.

***


# TODO

* 对视频、音频的支持。

*** 



# Requirements
* 使用Gallop实现网络图片加载部分依赖于[SDWebImage](https://github.com/rs/SDWebImage) 'SDWebImage', '~>3.7'
* HTML解析依赖libxml2库


# Installation

1. 在XCode的Build Phases-> Link Binary With Libraries中添加libxml2.tbd库
2. 在XCode的Build Setting->Header Search Paths中添加‘/usr/include/libxml2’
3. 安装[SDWebImage](https://github.com/rs/SDWebImage)
4. 将Gallop文件夹下的.h及.m文件添加到你的工程当中
5. #import "Gallop.h"


# Usage

## API Quickstart

```objc
#import "Gallop.h"
```

1.生成一个文本模型


```objc
LWTextStorage* textStorage = [[LWTextStorage alloc] init];
textStorage.text = @"waynezxcv";
textStorage.font = [UIFont systemFontOfSize:15.0f];
textStorage.textColor = RGB(113, 129, 161, 1);

/***  为文本添加点击链接事件  ***/
[textStorage addLinkWithData:data
inRange:NSMakeRange(0,statusModel.name.length)
linkColor:RGB(113, 129, 161, 1)
highLightColor:RGB(0, 0, 0, 0.15)];

/***  点击链接回调  ***/
- (void)lwAsyncDisplayView:(LWAsyncDisplayView *)asyncDisplayView didCilickedLinkWithfData:(id)data;

/***  用本地图片替换掉指定位置的文字  ***/
[textStorage lw_replaceTextWithImage:[UIImage imageNamed:@"img"]
contentMode:UIViewContentModeScaleAspectFill
imageSize:CGSizeMake(60, 60)
alignment:LWTextAttachAlignmentTop
range:NSMakeRange(webImageTextStorage.text.length - 7, 0)];


/***  用网络图片替换掉指定位置的文字  ***/
[textStorage lw_replaceTextWithImageURL:[NSURL URLWithString:@"https://avatars0.githubusercontent.com/u/8408918?v=3&s=460"]
contentMode:UIViewContentModeScaleAspectFill
imageSize:CGSizeMake(60, 60)
alignment:LWTextAttachAlignmentTop
range:NSMakeRange(webImageTextStorage.text.length - 7, 0)];

/***  用UIView替换掉指定位置的文字  ***/
[textStorage lw_replaceTextWithView:[[UISwitch alloc] initWithFrame:CGRectMake(0, 0, 60.0f, 30.0f)]
contentMode:UIViewContentModeScaleAspectFill
size:CGSizeMake(60.0f, 30.0f)
alignment:LWTextAttachAlignmentTop
range:NSMakeRange(1,0)];

```

2.生成一个图片模型
```objc

/***  本地图片  ***/
LWImageStorage* imamgeStorage = [[LWImageStorage alloc] init];
imamgeStorage.contents = [UIImage imageNamed:@"pic.jpeg"];
imamgeStorage.frame = CGRectMake(textStorage.left, textStorage.bottom + 20.0f, 80, 80);
imamgeStorage.cornerRadius = 40.0f;//设置圆角半径


/***  网络图片  ***/
LWImageStorage* imamgeStorage = [[LWImageStorage alloc] init];
imamgeStorage.contents = [NSURL URLWithString:@"https://avatars0.githubusercontent.com/u/8408918?v=3&s=460"];
imamgeStorage.frame = CGRectMake(textStorage.left, textStorage.bottom + 20.0f, 80, 80);
imamgeStorage.cornerRadius = 40.0f;

/***  点击图片回调  ***/
- (void)lwAsyncDisplayView:(LWAsyncDisplayView *)asyncDisplayView didCilickedImageStorage:(LWImageStorage *)imageStorage touch:(UITouch *)touch;

```

3.生成布局模型
```objc
LWLayout* layout = [[LWLayout alloc] init];

/***  将LWstorage实例添加到layout当中  ***/
[layout addStorage:textStorage];
[layout addStorage:imamgeStorage];
```

4.创建LWAsyncDisplayView，并将LWLayout实例赋值给创建LWAsyncDisplayView对象

```objc
LWAsyncDisplayView* asyncDisplayView = [[LWAsyncDisplayView alloc] initWithFrame:CGRectZero];
asyncDisplayView.layout = layout;
[self.view addSubview:asyncDisplayView];


```


5.解析HTML生成iOS原生页面

```objc

/*** 创建LWHTMLDisplayView  ***/
LWHTMLDisplayView* htmlView = [[LWHTMLDisplayView alloc] initWithFrame:self.view.bounds];
htmlView.parentVC = self;
htmlView.displayDelegate = self;
[self.view addSubview:htmlView];

/***  获取LWStorageBuilder  ***/
LWStorageBuilder* builder = htmlView.storageBuilder;

/***  创建LWLayout  ***/
LWLayout* layout = [[LWLayout alloc] init];

/***  创建LWHTMLTextConfig  ***/
LWHTMLTextConfig* contentConfig = [[LWHTMLTextConfig alloc] init];
contentConfig.font = [UIFont fontWithName:@"Heiti SC" size:15.0f];
contentConfig.textColor = RGB(50, 50, 50, 1);
contentConfig.linkColor = RGB(232, 104, 96,1.0f);
contentConfig.linkHighlightColor = RGB(0, 0, 0, 0.35f);

/***  创建另一个LWHTMLTextConfig  ***/
LWHTMLTextConfig* strongConfig = [[LWHTMLTextConfig alloc] init];
strongConfig.font = [UIFont fontWithName:@"STHeitiSC-Medium" size:15.0f];
strongConfig.textColor = [UIColor blackColor];


/***  通过XPath解析HTML并生成LWStorage  ***/
/***  通过UIEdgeInsets设置布局传入第二个参数 ***/
/*** 标签名对应的LWHTMLTextConfig以字典的Key-Value格式传入最后一个参数 ***/
[builder createLWStorageWithXPath:@"//div[@class='content']/p"
edgeInsets:UIEdgeInsetsMake([layout suggestHeightWithBottomMargin:10.0f], 10.0f, 10.0, 10.0f)
configDictionary:@{@"p":contentConfig,
@"strong":strongConfig,
@"em":strongConfig}];

/***  获取生成的LWStorage实例数组  ***/
NSArray* storages = builder.storages;

/***  添加到LWLayout实例  ***/
[layout addStorages:storages];

/***  给LWHTMLDisplayView对象并赋值  ***/
htmlView.layout = layout;

```

XPath教程: http://www.w3school.com.cn/xpath/index.asp

* **如果需要更加详细的内容，请看各个头文件和Demo，有详细的注释**


# 正在不断完善中...
# 有任何问题请添加issue

# License

Gallop is available under the MIT license. See the LICENSE file for more info.


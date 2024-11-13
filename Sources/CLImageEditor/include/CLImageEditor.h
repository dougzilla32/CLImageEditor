//
//  CLImageEditor.h
//
//  Created by sho yakushiji on 2013/10/17.
//  Copyright (c) 2013年 CALACULU. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for MyObjCLibrary.
FOUNDATION_EXPORT double MyObjCLibraryVersionNumber;

//! Project version string for MyObjCLibrary.
FOUNDATION_EXPORT const unsigned char MyObjCLibraryVersionString[];

#import "CLImageEditorTheme.h"
#import "CLImageToolInfo.h"

#import <UIKit/UIKit.h>

@protocol CLImageEditorDelegate;
@protocol CLImageEditorTransitionDelegate;

@interface CLImageEditor : UIViewController
{
    
}
@property (nonatomic, weak) id<CLImageEditorDelegate> delegate;
@property (nonatomic, readonly) CLImageEditorTheme *theme;
@property (nonatomic, readonly) CLImageToolInfo *toolInfo;

- (id)initWithImage:(UIImage*)image;
- (id)initWithImage:(UIImage*)image delegate:(id<CLImageEditorDelegate>)delegate;
- (id)initWithDelegate:(id<CLImageEditorDelegate>)delegate;

- (void)showInViewController:(UIViewController<CLImageEditorTransitionDelegate>*)controller withImageView:(UIImageView*)imageView;

- (void)refreshToolSettings;

@end



@protocol CLImageEditorDelegate <NSObject>
@optional
- (void)imageEditor:(CLImageEditor*)editor didFinishEdittingWithImage:(UIImage*)image __attribute__ ((deprecated));
- (void)imageEditor:(CLImageEditor*)editor didFinishEditingWithImage:(UIImage*)image;
- (void)imageEditorDidCancel:(CLImageEditor*)editor;

@end


@protocol CLImageEditorTransitionDelegate <CLImageEditorDelegate>
@optional
- (void)imageEditor:(CLImageEditor*)editor willDismissWithImageView:(UIImageView*)imageView canceled:(BOOL)canceled;
- (void)imageEditor:(CLImageEditor*)editor didDismissWithImageView:(UIImageView*)imageView canceled:(BOOL)canceled;

@end

#import "ViewController/_CLImageEditorViewController.h"
#import "ImageTools/CLImageToolBase.h"
#import "ImageTools/ToolSettings/CLCircleView.h"
#import "ImageTools/ToolSettings/CLToolbarMenuItem.h"
#import "ImageTools/ToolSettings/CLColorPickerView.h"
#import "ImageTools/ToolSettings/CLImageToolProtocol.h"
#import "ImageTools/ToolSettings/UIView+CLImageToolInfo.h"
#import "ImageTools/ToolSettings/CLImageToolSettings.h"
#import "ImageTools/ToolSettings/CLImageEditorTheme+Private.h"
#import "ImageTools/ToolSettings/CLImageToolInfo+Private.h"
//#import "ImageTools/CLClippingTool/CLClippingTool.h"
#import "ImageTools/CLEffectTool/CLEffectBase.h"
//#import "ImageTools/CLEffectTool/CLEffectTool.h"
#import "ImageTools/CLEffectTool/CLEffect/CLSpotEffect.h"
#import "ImageTools/CLEffectTool/CLEffect/CLHighlightShadowEffect.h"
#import "ImageTools/CLEffectTool/CLEffect/CLPosterizeEffect.h"
#import "ImageTools/CLEffectTool/CLEffect/CLPixellateEffect.h"
#import "ImageTools/CLEffectTool/CLEffect/CLBloomEffect.h"
#import "ImageTools/CLEffectTool/CLEffect/CLGloomEffect.h"
#import "ImageTools/CLEffectTool/CLEffect/CLHueEffect.h"
//#import "ImageTools/CLRotateTool/CLRotateTool.h"
//#import "ImageTools/CLAdjustmentTool/CLAdjustmentTool.h"
//#import "ImageTools/CLFilterTool/CLFilterTool.h"
#import "ImageTools/CLFilterTool/CLFilterBase.h"
//#import "ImageTools/CLDrawTool/CLDrawTool.h"
//#import "ImageTools/CLToneCurveTool/CLToneCurveTool.h"
//#import "ImageTools/CLBlurTool/CLBlurTool.h"
#import "Utils/CLSplineInterpolator.h"
#import "Utils/UIImage+Utility.h"
#import "Utils/CLClassList.h"
#import "Utils/UIView+Frame.h"
#import "Utils/UIDevice+SystemVersion.h"

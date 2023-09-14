/*
 *  (c) 2022 BlackBerry Limited. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
/**
 The type of common settings cell used by common settings section
 */
typedef NS_ENUM(NSUInteger, GTLCommonSettingsCellType) {
    /// Cell type that represents 'Change Password' item
    GTLCommonSettingsCellTypeChangePassword = 1,
    /// Cell type that represents 'Launcher' item
    GTLCommonSettingsCellTypeLauncher,
    /// Cell type that represents 'Upload Logs' item
    GTLCommonSettingsCellTypeUploadLogs
};

/**
 Configuration API to configure Launcher Common settings section table view cells styles.
 
 Host application can configure styles for Common settings section by creating instance of this class and returning it in  ``GTLauncherViewControllerDelegate/commonSettingsCellConfigurationForType:launcherViewController:`` of the ``GTLauncherViewControllerDelegate`` method:
 ````
 - (GTLCommonSettingsCellConfiguration *)commonSettingsCellConfigurationForType:(GTLCommonSettingsCellType)cellType launcherViewController:(GTLauncherViewController *)controller {
    GTLCommonSettingsCellConfiguration *style = [GTLCommonSettingsCellConfiguration defaultConfigurationForType:cellType];
    /// Do updates
    return style;
 }
 ````
 */
OBJC_EXPORT
@interface GTLCommonSettingsCellConfiguration : NSObject
/// Cell background color. Default is `nil`: system default color will be used.
@property (nonatomic, strong, nonnull) UIColor *backgroundColor;
/// Setting name text color. Default is black.
@property (nonatomic, strong, nonnull) UIColor *textColor;
/// Setting name text font. Default is ``UIFontTextStyleBody`` font.
@property (nonatomic, strong, nonnull) UIFont *textFont;
/// Icon to be displayed to the left of  setting name text, by default it is `nil`, no icon will be displayed.
@property (nonatomic, strong, nullable) UIImage *icon;
/// Tint color for icon, by default it is `nil`, no tint will be applied. Has no effect when `icon` is `nil`.
@property (nonatomic, strong, nullable) UIColor *iconTintColor;
/// Table view cell accessory type to be displayed on the right, by default is ``UITableViewCellAccessoryNone``.
@property (nonatomic, assign) UITableViewCellAccessoryType accessoryType;
/// Content left margin delta. This might be needed to align custom table view cells with Common settings table view cells. By default is `0`.
@property (nonatomic, assign) CGFloat leftMarginDelta;
/// Table view cell accessory view, by default is nil
@property (nonatomic, strong, nullable) UIView       *accessoryView;
/**
 This method provides ability to get default style for provided table view cell type. It might be usefull in case style updates needed only font or color for particular table view cell type.
 - parameters:
    - type: ``GTLCommonSettingsCellType`` type of cell.
 - returns: ``GTLCommonSettingsCellConfiguration`` default style for provided table view cell type.
 */
+ (GTLCommonSettingsCellConfiguration *)defaultConfigurationForType:(GTLCommonSettingsCellType)type;
@end

NS_ASSUME_NONNULL_END

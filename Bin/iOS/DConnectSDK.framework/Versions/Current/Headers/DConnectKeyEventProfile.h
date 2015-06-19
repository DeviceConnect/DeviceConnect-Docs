//
//  DConnectKeyEventProfile.h
//  DConnectSDK
//
//  Copyright (c) 2015 NTT DOCOMO,INC.
//  Released under the MIT license
//  http://opensource.org/licenses/mit-license.php
//

/*!
 @file
 @brief Provides functionality to implement the Key Event profile.
 @author NTT DOCOMO
 */
#import <DConnectSDK/DConnectProfile.h>

/*!
 @brief Profile name
 */
extern NSString *const DConnectKeyEventProfileName;

/*!
 @brief Attribute: down.
 */
extern NSString *const DConnectKeyEventProfileAttrOnDown;

/*!
 @brief Attribute: up.
 */
extern NSString *const DConnectKeyEventProfileAttrOnUp;

/*!
 @brief Parameter: keyevent.
 */
extern NSString *const DConnectKeyEvnetProfileParamKeyEvent;

/*!
 @brief Parameter: id.
 */
extern NSString *const DConnectKeyEventProfileParamId;

/*!
 @brief Parameter: config.
 */
extern NSString *const DConnectKeyEventProfileParamConfig;

/*!
 @brief Parameter: Key Type(KEYTYPE_STD_KEY).
 */
extern int const DConnectKeyEventProfileKeyTypeStdKey;

/*!
 @brief Parameter: Key Type(KEYTYPE_MEDIA_CTRL).
 */
extern int const DConnectKeyEventProfileKeyTypeMediaCtrl;

/*!
 @brief Parameter: Key Type(KEYTYPE_DPAD_BUTTON).
 */
extern int const DConnectKeyEventProfileKeyTypeDpadButton;

/*!
 @brief Parameter: Key Type(KEYTYPE_USER).
 */
extern int const DConnectKeyEventProfileKeyTypeUser;


@class DConnectKeyEventProfile;

/*!
 @protocol DConnectKeyEventProfileDelegate
 @brief Delegate for request notification of key event profile API.
 
 Delegate for request notification of button profile API.
 */
@protocol DConnectKeyEventProfileDelegate <NSObject>
@optional

#pragma mark - Get Methods

/*!
 @brief Notify delegate that it has received a "get ondown request".
 
 Notify delegate that profile has received a "get ondown request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Key Event Down API [GET]
 </p>
 
 @param[in] profile Object of DConnectKeyEventProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectKeyEventProfile *)profile didReceiveGetOnDownRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId;

/*!
 @brief Notify delegate that it has received a "get onup request".
 
 Notify delegate that profile has received a "get onup request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Key Event Up API [GET]
 </p>
 
 @param[in] profile Object of DConnectKeyEventProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectKeyEventProfile *)profile didReceiveGetOnUpRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId;

#pragma mark - Put Methods
#pragma mark Event Registration

/*!
 @brief Notify delegate that it has received a "ondown event registration request".
 
 Notify delegate that profile has received a "ondown event registration request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Key Event Down Event API [Register]
 </p>
 
 @param[in] profile Object of DConnectKeyEventProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectKeyEventProfile *)profile didReceivePutOnDownRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId
      sessionKey:(NSString *)sessionKey;

/*!
 @brief Notify delegate that it has received a "onup event registration request".
 
 Notify delegate that profile has received a "onup event registration request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Key Event Up Event API [Register]
 </p>
 
 @param[in] profile Object of DConnectKeyEventProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectKeyEventProfile *)profile didReceivePutOnUpRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId
      sessionKey:(NSString *)sessionKey;

#pragma mark - Delete Methods
#pragma mark Event Unregistration

/*!
 @brief Notify delegate that it has received a "ondown event release request"
 
 Notify delegate that profile has received a "ondown event release request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Key Event Down Event API [Unregister]
 </p>
 
 @param[in] profile Object of DConnectKeyEventProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectKeyEventProfile *)profile didReceiveDeleteOnDownRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response serviceId:(NSString *)serviceId sessionKey:(NSString *)sessionKey;

/*!
 @brief Notify delegate that it has received a "onup event release request"
 
 Notify delegate that profile has received a "onup event release request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Key Event Up Event API [Unregister]
 </p>
 
 @param[in] profile Object of DConnectKeyEventProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectKeyEventProfile *)profile didReceiveDeleteOnUpRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response serviceId:(NSString *)serviceId sessionKey:(NSString *)sessionKey;

@end

/*!
 @class DConnectKeyEventProfile
 @brief Key Event Profile.
 
 Receive request to the Key Event Profile API.
 The received request is reported to the delegate for each API.
 */
@interface DConnectKeyEventProfile : DConnectProfile

/*!
 @brief Delegate object for DConnectKeyEventProfile.
 
 The delegate must implement the @link DConnectKeyEventProfileDelegate @endlink .
 The delegate is not retain.
 */
@property (nonatomic, weak) id<DConnectKeyEventProfileDelegate> delegate;

#pragma mark - Setters

/*!
 @brief Set key event information to message.
 @param[in] keyevent key event information.
 @param[in,out] message message for storing key event information.
 */
+ (void) setKeyEvent:(DConnectMessage *)keyevent target:(DConnectMessage *)message;

/*!
 @brief Set the identification number to message.
 @param[in] id identification number.
 @param[in,out] message message for storing identification number.
 */
+ (void) setId:(int)id target:(DConnectMessage *)message;

/*!
 @brief Set key event configure to message.
 @param[in] config button configer.
 @param[in,out] message message for storing button configure.
 */
+ (void) setConfig:(NSString *)config target:(DConnectMessage *)message;

@end

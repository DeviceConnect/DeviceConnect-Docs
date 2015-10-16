//
//  DConnectTouchProfile.h
//  DConnectSDK
//
//  Copyright (c) 2015 NTT DOCOMO,INC.
//  Released under the MIT license
//  http://opensource.org/licenses/mit-license.php
//

/*!
 @file
 @brief Provides functionality to implement the Touch profile.
 @author NTT DOCOMO
 */
#import <DConnectSDK/DConnectProfile.h>

/*!
 @brief Profile name
 */
extern NSString *const DConnectTouchProfileName;

/*!
 @brief Attribute: ontouch.
 */
extern NSString *const DConnectTouchProfileAttrOnTouch;

/*!
 @brief Attribute: ontouchstart.
 */
extern NSString *const DConnectTouchProfileAttrOnTouchStart;

/*!
 @brief Attribute: ontouchend.
 */
extern NSString *const DConnectTouchProfileAttrOnTouchEnd;

/*!
 @brief Attribute: ondoubletap.
 */
extern NSString *const DConnectTouchProfileAttrOnDoubleTap;

/*!
 @brief Attribute: ontouchmove.
 */
extern NSString *const DConnectTouchProfileAttrOnTouchMove;

/*!
 @brief Attribute: ontouchcancel.
 */
extern NSString *const DConnectTouchProfileAttrOnTouchCancel;

/*!
 @brief Parameter: touch.
 */
extern NSString *const DConnectTouchProfileParamTouch;

/*!
 @brief Parameter: touches.
 */
extern NSString *const DConnectTouchProfileParamTouches;

/*!
 @brief Parameter: id.
 */
extern NSString *const DConnectTouchProfileParamId;

/*!
 @brief Parameter: x.
 */
extern NSString *const DConnectTouchProfileParamX;

/*!
 @brief Parameter: y.
 */
extern NSString *const DConnectTouchProfileParamY;

@class DConnectTouchProfile;

/*!
 @protocol DConnectTouchProfileDelegate
 @brief Delegate for request notification of touch profile API.
 
 Delegate for request notification of touch profile API.
 */
@protocol DConnectTouchProfileDelegate <NSObject>
@optional

#pragma mark - Get Methods

/*!
 @brief Notify delegate that it has received a "get ontouch request".
 
 Notify delegate that profile has received a "get ontouch request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Touch API [GET]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceiveGetOnTouchRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId;

/*!
 @brief Notify delegate that it has received a "get ontouchstart request".
 
 Notify delegate that profile has received a "get ontouchstart request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] TouchStart API [GET]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceiveGetOnTouchStartRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId;

/*!
 @brief Notify delegate that it has received a "get ontouchend request".
 
 Notify delegate that profile has received a "get ontouchend request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] TouchEnd API [GET]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceiveGetOnTouchEndRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId;

/*!
 @brief Notify delegate that it has received a "get ondoubletap request".
 
 Notify delegate that profile has received a "get ondoubletap request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] DoubleTap API [GET]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceiveGetOnDoubleTapRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId;

/*!
 @brief Notify delegate that it has received a "get ontouchmove request".
 
 Notify delegate that profile has received a "get ontouchmove request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] TouchMove API [GET]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceiveGetOnTouchMoveRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId;

/*!
 @brief Notify delegate that it has received a "get ontouchcancel request".
 
 Notify delegate that profile has received a "get ontouchcancel request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] TouchCancel API [GET]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceiveGetOnTouchCancelRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId;

#pragma mark - Put Methods
#pragma mark Event Registration

/*!
 @brief Notify delegate that it has received a "ontouch event registration request".
 
 Notify delegate that profile has received a "ontouch event registration request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Touch Event API [Register]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceivePutOnTouchRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId
      sessionKey:(NSString *)sessionKey;

/*!
 @brief Notify delegate that it has received a "ontouchstart event registration request".
 
 Notify delegate that profile has received a "ontouchstart event registration request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] TouchStart Event API [Register]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceivePutOnTouchStartRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId
      sessionKey:(NSString *)sessionKey;

/*!
 @brief Notify delegate that it has received a "ontouchend event registration request".
 
 Notify delegate that profile has received a "ontouchend event registration request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Touch End Event API [Register]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceivePutOnTouchEndRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId
      sessionKey:(NSString *)sessionKey;

/*!
 @brief Notify delegate that it has received a "ondoubletap event registration request".
 
 Notify delegate that profile has received a "ondoubletap event registration request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Double Tap Event API [Register]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceivePutOnDoubleTapRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId
      sessionKey:(NSString *)sessionKey;

/*!
 @brief Notify delegate that it has received a "ontouchmove event registration request".
 
 Notify delegate that profile has received a "ontouchmove event registration request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Touch Move Event API [Register]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceivePutOnTouchMoveRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId
      sessionKey:(NSString *)sessionKey;

/*!
 @brief Notify delegate that it has received a "ontouchcancel event registration request".
 
 Notify delegate that profile has received a "ontouchcancel event registration request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Touch Cancel Event API [Register]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceivePutOnTouchCancelRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId
      sessionKey:(NSString *)sessionKey;

#pragma mark - Delete Methods
#pragma mark Event Unregistration

/*!
 @brief Notify delegate that it has received a "ontouch event release request"
 
 Notify delegate that profile has received a "ontouch event release request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Touch Event API [Unregister]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] deviceId device ID.
 @param[in] serviceId service ID.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceiveDeleteOnTouchRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response serviceId:(NSString *)serviceId sessionKey:(NSString *)sessionKey;

/*!
 @brief Notify delegate that it has received a "ontouchstart event release request"
 
 Notify delegate that profile has received a "ontouchstart event release request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Touch Start Event API [Unregister]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceiveDeleteOnTouchStartRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response serviceId:(NSString *)serviceId sessionKey:(NSString *)sessionKey;

/*!
 @brief Notify delegate that it has received a "ontouchend event release request"
 
 Notify delegate that profile has received a "ontouchend event release request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Touch End Event API [Unregister]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceiveDeleteOnTouchEndRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response serviceId:(NSString *)serviceId sessionKey:(NSString *)sessionKey;

/*!
 @brief Notify delegate that it has received a "ondoubletap event release request"
 
 Notify delegate that profile has received a "ondoubletap event release request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Double Tap Event API [Unregister]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceiveDeleteOnDoubleTapRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response serviceId:(NSString *)serviceId sessionKey:(NSString *)sessionKey;

/*!
 @brief Notify delegate that it has received a "ontouchmove event release request"
 
 Notify delegate that profile has received a "ontouchmove event release request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Touch Move Event API [Unregister]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceiveDeleteOnTouchMoveRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response serviceId:(NSString *)serviceId sessionKey:(NSString *)sessionKey;

/*!
 @brief Notify delegate that it has received a "ontouchcancel event release request"
 
 Notify delegate that profile has received a "ontouchcancel event release request".<br>
 If it is not implemented, "Not support Error" is returned.
 
 <p>
 [Corresponding API] Touch Cancel Event API [Unregister]
 </p>
 
 @param[in] profile Object of DConnectTouchProfile to notify this event.
 @param[in] request request.
 @param[in,out] response response.
 @param[in] serviceId service ID.
 @param[in] sessionKey sessionKey.
 @retval YES Response parameters return.
 @retval NO Response parameters no-return. be returned in @link DConnectManager::sendResponse: @endlink .
 */
- (BOOL) profile:(DConnectTouchProfile *)profile didReceiveDeleteOnTouchCancelRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response serviceId:(NSString *)serviceId sessionKey:(NSString *)sessionKey;

@end

/*!
 @class DConnectTouchProfile
 @brief Touch Profile.
 
 Receive request to the Touch Profile API.
 The received request is reported to the delegate for each API.
 */
@interface DConnectTouchProfile : DConnectProfile

/*!
 @brief Delegate object for DConnectTouchProfile.
 
 The delegate must implement the @link DConnectTouchProfileDelegate @endlink .
 The delegate is not retain.
 */
@property (nonatomic, weak) id<DConnectTouchProfileDelegate> delegate;

#pragma mark - Setters

/*!
 @brief Set touch information to message.
 @param[in] touch touch information.
 @param[in,out] message message for storing touch information.
 */
+ (void) setTouch:(DConnectMessage *)touch target:(DConnectMessage *)message;

/*!
 @brief Set touch coordinate information to message.
 @param[in] touches touch coordinate information.
 @param[in,out] message message for storing touch coordinate information.
 */
+ (void) setTouches:(DConnectArray *)touches target:(DConnectMessage *)message;

/*!
 @brief Set the identification number to message.
 @param[in] id identification number.
 @param[in,out] message message for storing identification number.
 */
+ (void) setId:(int)id target:(DConnectMessage *)message;

/*!
 @brief Set the X coordinates to message.
 @param[in] x X coordinate.
 @param[in,out] message message for storing X coordinate.
 */
+ (void) setX:(int)x target:(DConnectMessage *)message;

/*!
 @brief Set the Y coordinates to message.
 @param[in] y Y coordinate.
 @param[in,out] message message for storing Y coordinate.
 */
+ (void) setY:(int)y target:(DConnectMessage *)message;

@end

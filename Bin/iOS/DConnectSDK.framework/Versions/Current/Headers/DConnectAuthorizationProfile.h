//
//  DConnectAuthorizationProfile.h
//  DConnectSDK
//
//  Copyright (c) 2014 NTT DOCOMO,INC.
//  Released under the MIT license
//  http://opensource.org/licenses/mit-license.php
//

/*! 
 @file
 @brief Authrorizationプロファイルを実装するための機能を提供する。
 @author NTT DOCOMO
 */
#import <DConnectSDK/DConnectProfile.h>

/*!
 @brief プロファイル名。
 */
extern NSString *const DConnectAuthorizationProfileName;

/*!
 @brief アトリビュート: grant。
 */
extern NSString *const DConnectAuthorizationProfileAttrGrant;

/*!
 @brief アトリビュート: accesstoken。
 */
extern NSString *const DConnectAuthorizationProfileAttrAccessToken;

/*!
 @brief パラメータ: package。
 */
extern NSString *const DConnectAuthorizationProfileParamPackage;

/*!
 @brief パラメータ: clientId。
 */
extern NSString *const DConnectAuthorizationProfileParamClientId;

/*!
 @brief パラメータ: scope。
 */
extern NSString *const DConnectAuthorizationProfileParamScope;

/*!
 @brief パラメータ: scopes。
 */
extern NSString *const DConnectAuthorizationProfileParamScopes;

/*!
 @brief パラメータ: applicationName。
 */
extern NSString *const DConnectAuthorizationProfileParamApplicationName;

/*!
 @brief パラメータ: expirePeriod。
 */
extern NSString *const DConnectAuthorizationProfileParamExpirePeriod;

/*!
 @brief パラメータ: expire。
 */
extern NSString *const DConnectAuthorizationProfileParamExpire;

/*!
 @brief パラメータ: accessToken。
 */
extern NSString *const DConnectAuthorizationProfileParamAccessToken;

/*!
 @brief authorization_code。
 */
extern NSString *const DConnectAuthorizationProfileGrantTypeAuthorizationCode;

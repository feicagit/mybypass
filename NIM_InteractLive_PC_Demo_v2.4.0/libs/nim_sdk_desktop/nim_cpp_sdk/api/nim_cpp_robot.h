﻿/** @file nim_cpp_robot.h
  * @brief NIM SDK提供的Robot接口
  * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
  * @author Oleg
  * @date 2017.06.26
  */

#ifndef _NIM_SDK_CPP_ROBOT_H_
#define _NIM_SDK_CPP_ROBOT_H_

#include <string>
#include <functional>
#include "nim_robot_helper.h"

/**
* @namespace nim
* @brief namespace nim
*/
namespace nim
{

/** @class Robot
  * @brief NIM SDK提供的Robot接口
  */
class Robot
{
public:
	typedef std::function<void(NIMResCode rescode, NIMRobotInfoChangeType type, const RobotInfos&)> RobotChangedCallback;		/**< 机器人信息变更事件通知回调模板 */

/** @fn void RegChangedCallback(const RobotChangedCallback &callback, const std::string &json_extension = "")
  * 注册机器人变更广播通知
  * @param[in] callback		回调函数
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @return void 无返回值
  */
static void RegChangedCallback(const RobotChangedCallback &callback, const std::string &json_extension = "");

/** @fn char *QueryAllRobotInfosBlock(const std::string &json_extension = "")
  * 获取全部机器人信息(同步接口，堵塞NIM内部线程)
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @return char 机器人信息 json string array
  */
static RobotInfos QueryAllRobotInfosBlock(const std::string &json_extension = "");

/** @fn char *QueryRobotInfoByAccidBlock(const std::string &accid, const std::string &json_extension = "")
  * 获取指定机器人信息(同步接口，堵塞NIM内部线程)
  * @param[in] accid 机器人accid
  * @param[in] json_extension json扩展参数（备用，目前不需要）
  * @return char 机器人信息 json string
  */
static RobotInfo QueryRobotInfoByAccidBlock(const std::string &accid, const std::string &json_extension = "");

};

}//namespace

#endif //_NIM_SDK_CPP_ROBOT_H_
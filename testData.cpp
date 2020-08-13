/*
 * testData.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#include "CNCMonitoring.h"
#include <gtest/gtest.h>
 
TEST(CncMonitorTest, TemperatureMonitorStatus) {
    CNCMonitoring cncMonitorObj;
    ASSERT_EQ(false, cncMonitorObj.CheckStartupStatus(NO_POWER));
}
 
TEST(CncMonitorTest, TemperatureMonitorStatusNotOk) { 
    CNCMonitoring cncMonitorObj;
    ASSERT_EQ(false, cncMonitorObj.CheckStartupStatus(CONTROLLER_BOARD_NOT_OK));
}

TEST(CncMonitorTest, TemperatureMonitorStatusControllerNotOk) { 
    CNCMonitoring cncMonitorObj;
    ASSERT_EQ(false, cncMonitorObj.CheckStartupStatus(CONTROLLER_BOARD_NOT_OK));
}

TEST(CncMonitorTest, TemperatureMonitorLowerVal) { 
    CNCMonitoring cncMonitorObj;
    EXPECT_EQ(true, cncMonitorObj.CheckStartupStatus(ALL_OK));
    EXPECT_EQ(true, cncMonitorObj.Init("temperature", 35.0));
    EXPECT_EQ(true, cncMonitorObj.SetDataValue("temperature", 34.0));
    cncMonitorObj.DeInit();
}

TEST(CncMonitorTest, TemperatureMonitorHigherVal) { 
    CNCMonitoring cncMonitorObj;
    EXPECT_EQ(true, cncMonitorObj.CheckStartupStatus(ALL_OK));
    EXPECT_EQ(true, cncMonitorObj.Init("temperature", 35.0));
    EXPECT_EQ(false, cncMonitorObj.SetDataValue("temperature", 37.2));
    cncMonitorObj.DeInit();
}

TEST(CncMonitorTest, PartDimensionMonitorLowerVal) { 
    CNCMonitoring cncMonitorObj;
    ASSERT_EQ(true, cncMonitorObj.CheckStartupStatus(ALL_OK));
    ASSERT_EQ(true, cncMonitorObj.Init("partDimension", 0.5));
    ASSERT_EQ(true, cncMonitorObj.SetDataValue("partDimension", 0.4));
   cncMonitorObj.DeInit();
    }
TEST(CncMonitorTest, PartDimensionMonitorHigherVal) { 
    CNCMonitoring cncMonitorObj;
    ASSERT_EQ(true, cncMonitorObj.CheckStartupStatus(ALL_OK));
    ASSERT_EQ(true, cncMonitorObj.Init("partDimension", 0.5));
    ASSERT_EQ(false, cncMonitorObj.SetDataValue("partDimension", 0.7));
   cncMonitorObj.DeInit();
    }
TEST(CncMonitorTest, continuousOperMonitorLowerVal) {
    CNCMonitoring cncMonitorObj;
    ASSERT_EQ(true, cncMonitorObj.CheckStartupStatus(ALL_OK));
    ASSERT_EQ(true, cncMonitorObj.Init("continuousOper", 6));
    ASSERT_EQ(true, cncMonitorObj.SetDataValue("continuousOper", 5.75));
   cncMonitorObj.DeInit();
    } 
TEST(CncMonitorTest, continuousOperMonitorHigherVal) {
    CNCMonitoring cncMonitorObj;
    ASSERT_EQ(true, cncMonitorObj.CheckStartupStatus(ALL_OK));
    ASSERT_EQ(true, cncMonitorObj.Init("continuousOper", 6));
    ASSERT_EQ(false, cncMonitorObj.SetDataValue("continuousOper", 6.75));
    cncMonitorObj.DeInit();
    }       
TEST(CncMonitorTest, CncMonitor) {
    CNCMonitoring cncMonitorObj;
    ASSERT_EQ(true, cncMonitorObj.CheckStartupStatus(ALL_OK));
    ASSERT_EQ(true, cncMonitorObj.Init("temperature", 35));
    ASSERT_EQ(true, cncMonitorObj.Init("partDimension", 0.5));
    ASSERT_EQ(true, cncMonitorObj.Init("continuousOper", 6));
    ASSERT_EQ(true, cncMonitorObj.SetDataValue("temperature", 28));
    ASSERT_EQ(false, cncMonitorObj.SetDataValue("partDimension", 0.52));
    ASSERT_EQ(false, cncMonitorObj.SetDataValue("continuousOper", 6.25));
    cncMonitorObj.DeInit();
    }
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

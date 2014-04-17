#include "gtest/gtest.h"
#include "config_parser.h"

TEST(NginxConfigParserTest, SimpleConfig) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("example_config", &out_config);

  EXPECT_TRUE(success);
}

TEST(NginxConfigParserTest, NestedConfig) {
    NginxConfigParser parser_;
    NginxConfig out_config_;

    bool success = parser_.Parse("{ hello { foo bar; } }", &out_config_);
    EXPECT_TRUE(success);
}

#include "gtest/gtest.h"
#include "config_parser.h"

TEST(NginxConfigParserTest, SimpleConfig) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("example_config", &out_config);

  EXPECT_TRUE(success);
}

class NginxStringConfigTest : public :: testing::Test
{ 
  protected: bool ParseString(const std::string & config_string)
  { 
    std::stringstream config_stream(config_string); 
    return parser_.Parse(&config_stream, &out_config_); 
  } 
  NginxConfigParser parser_; 
  NginxConfig out_config_; 
};

TEST_F(NginxStringConfigTest, NestedConfig) {
    EXPECT_TRUE(ParseString("{ hello { foo bar; } }"));
}


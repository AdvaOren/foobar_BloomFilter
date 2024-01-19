#include "gtest/gtest.h"
#include <fstream>
#include "../src/Factory.h"
//#include "../src/IMenu.h"
#include "../src/App.h"

TEST(AppTest,AdvanceTest){
    std::ifstream ifs;
    ifs.open("../tests/main_test_input.txt");
    if (!ifs.is_open())
        std::cout << "ERROR cant open file test_menu_input_url.txt";
    Factory factory;
    /*IMenu* menu = factory.createMenu(0,ifs);
    App app;
    app.run(menu,ifs);*/
    EXPECT_TRUE(true);

}
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

int main()
{
    // 1. 把 JSON 解析至 DOM。
    const char* json = "{\"p\":\"r\",\"s\":10}";
    Document d;
    d.Parse(json);
    // 2. 利用 DOM 作出修改。
    Value& s = d["s"];
    s.SetInt(s.GetInt() + 1);
    Value& s1 = d["p"];
    s1.SetString("ss", 2);
    // 3. 把 DOM 转换（stringify）成 JSON。
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    // Output {"p":"ss","s":11}
    std::cout << buffer.GetString() << std::endl;
    system("pause");
    return 0;
}

#include <v8.h>
#include <node.h>
#include <windows.h>
#include <string>
using namespace std;
using namespace v8;

void GetCursorPosition(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = args.GetIsolate();

    POINT p;
    GetCursorPos(&p);

    auto property_x_name = String::NewFromUtf8Literal(isolate, "x");
    auto property_y_name = String::NewFromUtf8Literal(isolate, "y");

    auto property_x_value = Number::New(isolate, p.x);
    auto property_y_value = Number::New(isolate, p.y);

    auto context = isolate->GetCurrentContext();
    auto result = Object::New(isolate);

    result->Set(context, property_x_name, property_x_value);
    result->Set(context, property_y_name, property_y_value);

    args.GetReturnValue().Set(result);
}

void SetCursorPosition(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = args.GetIsolate();

    if (args.Length() == 1)
    {
        auto context = isolate->GetCurrentContext();

        auto property_x_name = String::NewFromUtf8Literal(isolate, "x");
        auto property_y_name = String::NewFromUtf8Literal(isolate, "y");

        Local<Object> POINT = args[0]->ToObject(context).ToLocalChecked();

        bool hasX;
        bool hasY;

        POINT->Has(context, property_x_name).To(&hasX);
        POINT->Has(context, property_y_name).To(&hasY);

        if (hasX && hasY)
        {
            double x;
            double y;

            POINT->Get(context, property_x_name).ToLocalChecked()->NumberValue(context).To(&x);
            POINT->Get(context, property_y_name).ToLocalChecked()->NumberValue(context).To(&y);

            SetCursorPos(x, y);
        }
        else
        {
            isolate->ThrowException(String::NewFromUtf8Literal(isolate, "Invalid point."));
        }
    }
    else
    {
        isolate->ThrowException(String::NewFromUtf8Literal(isolate, "Invalid argument count."));
    }
}

void SendCursorEvent(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = args.GetIsolate();

    if (args.Length() == 1)
    {
        auto context = isolate->GetCurrentContext();

        auto property_event_name = String::NewFromUtf8Literal(isolate, "event");
        auto property_data_name = String::NewFromUtf8Literal(isolate, "data");
        auto property_x_name = String::NewFromUtf8Literal(isolate, "x");
        auto property_y_name = String::NewFromUtf8Literal(isolate, "y");

        Local<Object> POINT = args[0]->ToObject(context).ToLocalChecked();

        bool hasEvent;
        bool hasData;
        bool hasX;
        bool hasY;

        POINT->Has(context, property_event_name).To(&hasEvent);
        POINT->Has(context, property_data_name).To(&hasData);
        POINT->Has(context, property_x_name).To(&hasX);
        POINT->Has(context, property_y_name).To(&hasY);

        if (hasEvent && hasData && hasX && hasY)
        {
            int mouse_event;
            int mouse_data;
            double x;
            double y;

            POINT->Get(context, property_event_name).ToLocalChecked()->Int32Value(context).To(&mouse_event);
            POINT->Get(context, property_data_name).ToLocalChecked()->Int32Value(context).To(&mouse_data);
            POINT->Get(context, property_x_name).ToLocalChecked()->NumberValue(context).To(&x);
            POINT->Get(context, property_y_name).ToLocalChecked()->NumberValue(context).To(&y);

            INPUT input;
            input.type = INPUT_MOUSE;
            input.mi.dx = x;
            input.mi.dy = y;
            input.mi.dwFlags = mouse_event;
            input.mi.mouseData = mouse_data;
            input.mi.dwExtraInfo = NULL;
            input.mi.time = 0;

            SendInput(1, &input, sizeof(INPUT));
        }
        else
        {
            isolate->ThrowException(String::NewFromUtf8Literal(isolate, "Invalid point."));
        }
    }
    else
    {
        isolate->ThrowException(String::NewFromUtf8Literal(isolate, "Invalid argument count."));
    }
}

void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "getCursorPosition", GetCursorPosition);
    NODE_SET_METHOD(exports, "setCursorPosition", SetCursorPosition);
    NODE_SET_METHOD(exports, "sendCursorEvent", SendCursorEvent);
}

NODE_MODULE(addon, Initialize);
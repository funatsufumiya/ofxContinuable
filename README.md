# ofxContinuable

[continuable](https://github.com/Naios/continuable) for openFrameworks (tested on v0.12.0, continuable version: 4.2.2)

- also includes [function2](https://github.com/Naios/function2) (4.2.4) as a dependency

## Usage

See [example](example). (Please use `projectGenerator` before run it)

```cpp
#include "continuable.hpp"

inline cti::continuable<std::string> start_greetings(std::string) {
  return cti::make_ready_continuable<std::string>("world");
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofLogToConsole();

    start_greetings("hello")
        .then([](std::string response) {
            ofLogNotice("ofApp") << "hello: " << response;
        })
        .then([]() {
            ofLogNotice("ofApp") << "waiting for 200ms";
            ofSleepMillis(200);
        })
        .then([]() {
            ofLogNotice("ofApp") << "done";
        });

    ofLogNotice("ofApp") << "normal log test";
}

// Result:
// [notice ] ofApp: hello: world
// [notice ] ofApp: waiting for 200ms
// [notice ] ofApp: done
// [notice ] ofApp: normal log test
```

## LICENSE

- continuable: [MIT License](https://github.com/Naios/continuable/blob/4.2.2/LICENSE.txt)
- function2: [BSL-1.0 License](https://github.com/Naios/function2/blob/4.2.4/LICENSE.txt)

NOTE: No specific copyright is claimed for this repository changes (for oF binding), but the [Apache License 2.0](LICENSE_APACHE) or [MIT License](LICENSE_MIT) can be applied if necessary.

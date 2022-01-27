const {getCursorPosition, setCursorPosition, sendCursorEvent} = require("./build/Release/node-cursor");

const cursorEvents = Object.freeze({
    LEFT_DOWN: 0x0002,
    LEFT_UP: 0x0004,
    RIGHT_DOWN: 0x0008,
    RIGHT_UP: 0x0010,
    MIDDLE_DOWN: 0x0020,
    MIDDLE_UP: 0x0040,
    WHEEL: 0x0800,
    MOUSEEVENTF_MOVE: 0x0001
});

module.exports = {
    getCursorPosition,
    setCursorPosition,
    sendCursorEvent,
    cursorEvents
}
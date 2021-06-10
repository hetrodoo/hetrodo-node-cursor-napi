interface POINT {
    x: number
    y: number
}

interface CursorEvent extends POINT {
    event: CursorEvents
    data: number
}

interface CursorEvents {
    LEFT_DOWN: number
    LEFT_UP: number
    RIGHT_DOWN: number
    RIGHT_UP: number
    MIDDLE_DOWN: number
    MIDDLE_UP: number
    WHEEL: number
}

declare const NodeCursor: {
    cursorEvents: CursorEvents;
    getCursorPosition(): POINT;
    setCursorPosition(position: POINT): void;
    sendCursorEvent(mouseEvent: CursorEvent): void;
}

export = NodeCursor;
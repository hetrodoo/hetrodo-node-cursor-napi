# [node-cursor](https://www.npmjs.com/package/node-cursor)

A node module to get information about the Windows mouse cursor, change its position and simulate clicks.

## Installation
#### You must have [Python](https://www.python.org/) and [Visual Studio Community](https://visualstudio.microsoft.com/pt-br/) installed in order to install this package.

```bash
yarn add node-cursor
```

or

```bash
npm install node-cursor
```

## Usage

#### Using import syntax

```typescript
import {getCursorPosition, setCursorPosition, sendCursorEvent, cursorEvents} from "node-cursor";

getCursorPosition();
//Return: { x: 0, y: 0 }

setCursorPosition({
    x: 0,
    y: 0
});

//Send mouse click at 0, 0
sendCursorEvent({
    event: cursorEvents.LEFT_DOWN,
    data: 0,
    x: 0,
    y: 0
});
sendCursorEvent({
    event: cursorEvents.LEFT_UP,
    data: 0,
    x: 0,
    y: 0
});

//Scroll wheel
sendCursorEvent({
    event: cursorEvents.WHEEL,
    data: 120, //amount of wheel movement
    x: 0,
    y: 0
});
```

#### Using require syntax

```javascript
const NodeCursor = require("node-cursor");

NodeCursor.getCursorPosition();
//Return: { x: 0, y: 0 }

NodeCursor.setCursorPosition({
    x: 0,
    y: 0
});

//Send mouse click at 0, 0
NodeCursor.sendCursorEvent({
    event: NodeCursor.cursorEvents.LEFT_DOWN,
    data: 0,
    x: 0,
    y: 0
});
NodeCursor.sendCursorEvent({
    event: NodeCursor.cursorEvents.LEFT_UP,
    data: 0,
    x: 0,
    y: 0
});

//Scroll wheel
NodeCursor.sendCursorEvent({
    event: NodeCursor.cursorEvents.WHEEL,
    data: 120, //amount of wheel movement
    x: 0,
    y: 0
});
```

#### Built-in Events:
```typescript
import {cursorEvents} from "node-cursor";

cursorEvents.LEFT_DOWN //0x0002
cursorEvents.LEFT_UP //0x0004
cursorEvents.RIGHT_DOWN //0x0008
cursorEvents.RIGHT_UP //0x0010
cursorEvents.MIDDLE_DOWN //0x0020
cursorEvents.MIDDLE_UP //0x0040
cursorEvents.WHEEL //0x0800
```

[All events](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-mouse_event#parameters)

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)
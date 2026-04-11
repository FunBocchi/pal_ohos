import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'liblaptop.so';
import { AppUtil } from '@pura/harmony-utils';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Stack() {
      XComponent({
        id: "pal_game_ui",
        type: XComponentType.SURFACE,
        libraryname: "laptop"
      })
    }
  }
}

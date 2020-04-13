# Optional

옵셔널이라는 존재는 Swift에는 메모리 주소를 직접 들여다 볼수 없어서 값이 들어있지 않다는 사실을 알려줄 무언가가 필요한데 이게 바로 Optional이다.



가장먼저 기존의 C는 -1,0, -999989등으로 값이 비어있다는 것을 알려줬지만, Swift에서는 좀더 확실히 표현할 방법을 찾았다. Optional String처럼 사용하는것.



Optional(not set, set)  String("Value")타입으로 기재하면 Optional 타입안에 associated로 String이 포함되어 있다고 생각하면 된다.

 

Optional타입에서 String값을 빼오는 방법은 !를 뒤에 붙이면 값을 꺼내올수 있다. 다만 값이 nil일경우 꺼내오게 되면 앱은 충돌이나며 버그가 된다.
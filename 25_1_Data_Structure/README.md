25-1학기 수강한 자료구조 과목 과제입니다.

1. Student List
   - vector를 이용한 학생 명부 관리 프로그램 만들기
   - vector의 여러 함수들(find_if, erase, emplace 등등)을 이용해보고, 학번을 통해 중복을 관리하는 기초적인 데이터 테이블 관리해보기
   - freind 함수의 operator overloading을 이용한 출력 형태 만들어주기

2. Pre-order Calculator
   - prefix 표현의 수식을 입력받아 계산 결과를 출력하기
   - 기초적인 Tree 구조를 Inheritance를 통해 만들고, abstract class 선언을 통해 각 클래스에 필요한 기능들 구현해보기
   - prefix 표현의 수식을 Tree 구조로 만들고, 올바른 traversal을 통해 계산하기

3. In-order formula
   - prefix 표현의 수식을 우리가 평상시 쓰고 있는 수식인 In-order 표현으로 바꿔 출력하기(예: - + 3 3 * 2 + 2 1 3 => 3 * 3 + 2 * ( 2 + 1 ) - 3 = 12)
   - dynamic_cast를 이용하여 노드의 부모를 알아내 알맞은 상황에서 괄호를 열고 닫아주기
   - function overriding을 통해 상황에 맞는 숫자나 연산부호 출력하기

4. Post-order Calculator
   - postfix 표현의 수식을 입력받아 계산 결과 출력하기
   - stack을 이용하여 적절한 상황에서 push, pop을 이용하여 맨 마지막 top에 계산 결과 남겨놓기
   - 만약 stack이 비어있거나 두 개 이상이 있는 경우 등을 대비한 exception handling 연습해보기
  
5. Find Path in New York
   - New York의 건물들의 좌표값과 건물 사이 거리가 담겨 있는 파일을 입력받은 후, 최단 경로에 해당되는 지점들을 출력하기
   - directed weighted graph 구조를 구현해보고, Dijkstra 알고리즘을 이용하여 vector에 최단 경로에 해당하는 지점 정보를 저장하기

# Patient-management-program

1. 개요   
레드블랙트리(red-black tree)를 이용하여 환자들의 정보를 효율적으로 관리하는 프로그램

2. 환자정보 형식   
  ① 환자번호 (기준키, 유일함): 1,000,000 ~ 1,999,999 사이의 정수.  
  ② 이름: 공백 없는 20 bytes 이내의 문자열. 예) “Mary”   
  ③ 연락처: 회원의 전화번호(공백 없는 11 bytes 이내의 문자열). 예) “01012345678”   
  ④ 주소 좌표 (x, y): x와 y는 각각 0 ~ 10,000 사이의 임의의 정수.   
  ⑤ 진료기록: 아래 정보들의 나열    
   - 병명: 공백 없는 20 bytes 이내의 문자열. 예) “Headache”    
   - 진료비: 10,000 ~ 100,000 사이의 정수   
  각 줄에 ①~⑤의 정보들이 차례로 공백으로 구분되어 저장된다: 환자번호 / 이름 / 연락처 / 주소의 x, y 좌표 / 진료기록   
  진료기록은 다음의 정보들을 원소로 저장한다: 병명 / 진료비   
      
3. 수행할 기능   
  (1) 신규 가입 (최초 진료)   
    - 질의형식: “I K N H Ax Ay DI C”    
        I: 환자를 신규 가입하는 질의를 나타내는 기호    
        K: 환자번호   
        N: 이름   
        H: 연락처    
        Ax: 주소의 x 좌표    
        Ay: 주소의 y 좌표    
        DI: 병명    
        C: 진료비    
    - 출력형식: “D S”   
        D: 트리에서 환자 정보가 저장된 노드의 깊이 (root의 깊이는 0)   
        S: 신규 가입 처리를 나타내는 정수(0 또는 1) (0: 거절, 1: 승인)   
    - 설명: 새로운 환자 정보를 입력받아 레드블랙트리에 노드를 삽입하고, 그 노드의 깊이를 출력한다. 만약 동일한 환자번호가 이미 존재한다면, 그 노드의 깊이를 출력하고 신규 가입은 거절된다.    
 (2) 환자 검색   
    - 질의형식: “F K”   
        F: 특정 환자를 검색하는 질의를 나타내는 기호    
        K: 환자번호   
    - 출력형식: “D N H Ax Ay” 또는 “Not found”    
        D: 트리에서 환자 정보가 저장된 노드의 깊이   
        N: 이름   
        H: 연락처    
        Ax: 주소의 x 좌표    
        Ay: 주소의 y 좌표    
    - 설명: 해당 환자를 탐색하여 존재하면 환자의 정보를 출력한다. 만약 존재하지 않으면, “Not found”(주의: 대•소문자, 띄어쓰기 등 정확히 일치시킬 것)를 출력한다.    
 
 (3) 추가 진료   
    - 질의형식: “A K DI C”    
      A: 특정 환자에 대해 새로운 진료 정보를 추가하는 질의를 나타내는 기호    
      K: 환자번호   
      DI: 병명    
      C: 진료비    
    - 출력형식: “D” 또는 “Not found”    
      D: 트리에서 환자 정보가 저장된 노드의 깊이   
    - 설명: 해당 환자를 탐색하여 입력받은 진료 내용을 진료기록에 추가하고, 환자에 대한 노드의 깊이를 출력한다. 만약 환자가 존재하지 않는 경우, “Not found”를 출력한다.    
 
 (4) 유행병 조사    
    - 질의형식 : “E DI”   
      E: 마지막에 진료받은 병명을 기준으로 특정 병명을 수를 집계하는 질의를 나타내는 기호    
      DI: 병명    
    - 출력형식: “T”   
      T: 모든 환자들의 진료기록에서 마지막으로 추가된 병명이 입력으로 주어진 병명과 같은 환자의 수(T ≥ 0)    
    - 설명: 트리에 저장된 모든 환자들에 대해, 마지막으로 진단받은 병명이 입력으로 주어진 병명과 동일하면 집계하고, 집계된 수를 출력하여 유행성의 정도를 파악한다. 편의상, 골절 같은 전염성이 없는 병명도 유행병으로 간주한다.    

4. 입출력 제한사항   
  (1) 질의는 최대 100,000개가 입력된다.    
  (2) 전체 질의에 대해 2초의 제한시간 이내에 수행되어야 한다.    
  (3) 제시한 입출력 형식대로 표준 입출력을 사용하여 처리한다.   
  (4) 문제에서 설명되지 않은 예외처리할 질의는 입력되지 않는다.    

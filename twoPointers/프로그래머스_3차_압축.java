import java.util.*;

class Solution {
    
	static HashMap<String, Integer> map = new HashMap<>();
	static ArrayList<Integer> list = new ArrayList<>();
	
	public static void init() {
		for(int i = 0; i < 26; i++) {
			map.put(Character.toString('A' + i), i+1);
		}
	}
    
    public int[] solution(String msg) {
		init();
		int value = 27;
		boolean isEnd = false;
		String preWord ="";
		for(int i = 0; i < msg.length(); i++) {
			String word = Character.toString(msg.charAt(i));
			while(map.containsKey(word)) {
				i++;
				preWord = word;
				if(i == msg.length()) {
					isEnd = true;
					break;
				}
				word += Character.toString(msg.charAt(i));
			}
			
			list.add(map.get(preWord));
			if(isEnd) {
				break;
			}
			map.put(word, value++);
			i--;
		}

		int[] answer = new int[list.size()];
		for(int i = 0; i < answer.length; i++) {
			answer[i] = list.get(i);
		}
        
        return answer;
    }
}
import java.util.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

class Solution {
    
    public static String changeString(String str) {
        for(int i = 0; i < str.length() / 2; i++) {
		    str = str.replace("C#", "c");
            str = str.replace("D#", "d");
	        str = str.replace("F#", "f");
	        str = str.replace("G#", "g");
	        str = str.replace("A#", "A");
	    }
        return str;
    }
    
    public String solution(String m, String[] musicinfos) {    	
		String answerSong = "";
		int answerSongMinute = Integer.MIN_VALUE;
		
		long count = m.chars().filter(ch -> ch == '#').count();
        int minute = m.length() - (int)count;
        
        m = changeString(m);
        
        SimpleDateFormat dateFormat = new SimpleDateFormat("HH:mm");
        Date d1 = null;
        Date d2 = null;
        
        for(int i = 0; i < musicinfos.length; i++) {
            String[] arr = musicinfos[i].split(",");       
            try {
        		d1 = dateFormat.parse(arr[0]);
        		d2 = dateFormat.parse(arr[1]);
        	} catch (ParseException e) {
        	    e.printStackTrace();
        	}
        	
        	long diff = d2.getTime() - d1.getTime();        
        	int diffMinutes = (int)(diff / (60 * 1000));          
        	
            if(diffMinutes < minute)
            	continue;
            
            String songInfo = changeString(arr[3]);       
            String tempSongInfo = "";
            if(diffMinutes >= minute) {   	
            	int repeat = diffMinutes / songInfo.length();
            	int mod = diffMinutes % songInfo.length();
            	
            	while(repeat > 0) {
            		tempSongInfo += songInfo;
            		repeat--;
            	}
            	
            	tempSongInfo += songInfo.substring(0, mod);
            	if(tempSongInfo.contains(m)) {
            		if(answerSongMinute < diffMinutes) {
            			answerSong = arr[2];
                		answerSongMinute = diffMinutes;
            		}
            	}
            }      
        }
        
        if(answerSong.isEmpty())
        	answerSong = "(None)";
        
        return answerSong;
    }
}
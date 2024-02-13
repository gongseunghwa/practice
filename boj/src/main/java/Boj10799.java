import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 *  1. 막대 하나 하나씩 사이에 괄호 + 1 로 계산해서 더한다.
 *  2. 겹치는 막대의 경우에는 * 겹치는 수 로 계산해서 더한다.
 *
 *  자른수 + 막대수 = 전체 조각 수이고
 *
 *  배열에 ( 일떄 put  ) 일때 pop () 가 연속으로 나온 상황에서 stack.size() * n
 */
public class Boj10799 {
    private static final Stack<String> stack = new Stack<>();
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int barCount = 0;
        int sum = 0;
        while(st.hasMoreTokens()) {
            String tmp = st.nextToken();
            for(int i = 0 ; i< tmp.length(); i++) {


                if(tmp.charAt(i) == ')') {
                    stack.pop();
                    if(tmp.charAt(i-1) == '(') {
                        sum+=stack.size();
//                        System.out.println("sum +" + stack.size());
                    } else {
                        barCount++;
                    }
                }
            }
//            System.out.println("sum = " + sum );
//            System.out.println("barcount = " + barCount);
            sum+=barCount;
            System.out.println(sum);
        }
    }
}

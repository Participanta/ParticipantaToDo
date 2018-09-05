package JavaJni;

import android.util.Log;

/**
 * Created by A17028 on 2018/2/1.
 */

public class TestJniInterface {
    public byte[] Snbuffer = "jhdsfajhrfgdkhjdsjka".getBytes();
    private static final String TAG = "TestJniInterface";
    static {
        System.loadLibrary("nativelib");
    }
    public native static String JavaCallC(String data);

    public native static void CCallJava();

    public native static int add(int a,int b);

    public native static void CGetJavaPrams(TestJniInterface testJniInterface);

//    public static void MainTest(){
//        CCallJava(this);
//    }
    
    public void Test(String data){
        Log.i(TAG, "Test: "+data);
    }

    public void TestCGetJavaPrams(){
        CGetJavaPrams(this);
    }
}

package maxi.autel.com.ndkstudy;

import android.os.Bundle;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import JavaJni.TestJniInterface;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    TestJniInterface testJniInterface = new TestJniInterface();

    static Handler handler = new Handler();
    Button mTestBtn;
    TextView mInfoTxt;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mTestBtn = (Button) findViewById(R.id.btn_test);
        mInfoTxt = (TextView) findViewById(R.id.txt_info);
        mInfoTxt.setText(TestJniInterface.JavaCallC(""));
        mTestBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this, TestJniInterface.add(55,60)+"", Toast.LENGTH_SHORT).show();
                testJniInterface.TestCGetJavaPrams();

            }
        });

        findViewById(R.id.btn_1271).setOnClickListener(this);
        findViewById(R.id.btn_3647).setOnClickListener(this);
        findViewById(R.id.btn_clear).setOnClickListener(this);

    }

    public void CCallJava(){
        handler.post(new Runnable() {
            @Override
            public void run() {
                Toast.makeText(MainActivity.this, "1234456", Toast.LENGTH_SHORT).show();
            }
        });
    }

    @Override
    public void onClick(View v) {

    }
}

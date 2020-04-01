package pl.edu.pwr.student.a235420_ks_a5;

import android.Manifest;
import android.content.Context;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.telephony.SmsManager;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;







public class MainActivity extends AppCompatActivity {
    private Button importSimData;
    private Button sendMessage;
    private EditText smsMessagePhoneNumber;
    private EditText smsMessageText;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        importSimData = findViewById(R.id.button1);
        sendMessage = findViewById(R.id.button2);
        smsMessagePhoneNumber = findViewById(R.id.editText1);
        smsMessageText = findViewById(R.id.editText2);

        SmsReceiver myReciver = new SmsReceiver();

        Log.e("MAIN_ACTIV", "On create");

        // Manifest.permission.RECEIVE_SMS, Manifest.permission.SEND_SMS
        if (ContextCompat.checkSelfPermission(MainActivity.this, Manifest.permission.RECEIVE_SMS)
                != PackageManager.PERMISSION_GRANTED) {
            requestPermissions(new String[]{Manifest.permission.RECEIVE_SMS}, 1);
        }

        importSimData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (ContextCompat.checkSelfPermission(MainActivity.this, Manifest.permission.READ_PHONE_STATE)
                        != PackageManager.PERMISSION_GRANTED) {
                    requestPermissions(new String[]{Manifest.permission.READ_PHONE_STATE} , 2);
                    // Permission is not granted
                    Toast.makeText(MainActivity.this, "NO permission!",
                            Toast.LENGTH_LONG).show();
                    Toast.makeText(MainActivity.this, "Add permissions in settings",
                            Toast.LENGTH_LONG).show();

                }
                else {
                    Toast.makeText(MainActivity.this, "you have permission!",
                            Toast.LENGTH_LONG).show();

                    TelephonyManager tm = (TelephonyManager) MainActivity.this.getSystemService(Context.TELEPHONY_SERVICE);

                    int phoneType = tm.getPhoneType();
                    int phoneCallState = tm.getCallState();
                    int phoneNetworkType = tm.getDataNetworkType();
                    String phoneSubscriberId = tm.getSubscriberId();
                    Toast.makeText(MainActivity.this, String.valueOf(phoneType),
                            Toast.LENGTH_LONG).show();
                    Toast.makeText(MainActivity.this, String.valueOf(phoneCallState ),
                            Toast.LENGTH_LONG).show();
                    Toast.makeText(MainActivity.this, String.valueOf( phoneNetworkType),
                            Toast.LENGTH_LONG).show();
                    Toast.makeText(MainActivity.this, phoneSubscriberId,
                            Toast.LENGTH_LONG).show();
                }
            }
        });

    sendMessage.setOnClickListener(new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            if (ContextCompat.checkSelfPermission(MainActivity.this, Manifest.permission.SEND_SMS)
                    != PackageManager.PERMISSION_GRANTED) {
                requestPermissions(new String[]{Manifest.permission.SEND_SMS}, 3);
                //NO permission
                Toast.makeText(MainActivity.this, "NO permission!",
                        Toast.LENGTH_LONG).show();
                Toast.makeText(MainActivity.this, "Add permissions in settings",
                        Toast.LENGTH_LONG).show();}
            else {
                //you have
                String phoneNumber = smsMessagePhoneNumber.getText().toString();
                String smsText = smsMessageText.getText().toString();

                SmsManager smsManager = SmsManager.getDefault();
                smsManager.sendTextMessage(phoneNumber, null, smsText, null, null);
            }
        }
    });

    }
}



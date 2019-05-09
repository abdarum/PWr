package com.example.a235420_ks_a4;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    /*
    final EditText albumNumberCustom = findViewById(R.id.editText5);
    final TextView albumStudentName = findViewById(R.id.textView1);
    */

    private static EditText albumNumberCustom;
    private static TextView albumStudentName;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        /*
        final EditText albumNumberCustom = findViewById(R.id.editText5);
        final TextView albumStudentName = findViewById(R.id.textView1);
        */
        albumNumberCustom = findViewById(R.id.editText5);
        albumStudentName = findViewById(R.id.textView1);

        Button contacts = findViewById(R.id.button1);
        Button messages = findViewById(R.id.button2);
        Button maps = findViewById(R.id.button3);
        Button customActivity = findViewById(R.id.button4);

        final EditText messageNumber = findViewById(R.id.editText1);
        final EditText messageValue = findViewById(R.id.editText2);
        final EditText latitudeMap = findViewById(R.id.editText3);
        final EditText longtitudeMap = findViewById(R.id.editText4);



        contacts.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent contactsIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("content://contacts/people/"));
                startActivity(contactsIntent);
            }
        });

        messages.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent messagesIntent = new Intent(Intent.ACTION_SENDTO, Uri.parse("smsto:"+messageNumber.getText().toString()));
                messagesIntent.putExtra("sms_body",  messageValue.getText().toString());
                startActivity(messagesIntent);
            }
        });

        maps.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent mapsIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("geo:"+latitudeMap.getText().toString()+","+longtitudeMap.getText().toString()+"&z=16"));
                startActivity(mapsIntent);
            }
        });


        customActivity.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // przykład 17
                Intent customIntent = new Intent(MainActivity.this, CustomActivity.class);
                Bundle myDataTable = new Bundle();
                myDataTable.putString("idx", albumNumberCustom.getText().toString());
                /*
                int idx_value = Integer.parseInt(albumNumberCustom.getText().toString());
                myDataTable.putInt("idx", idx_value);
                */
                customIntent.putExtras(myDataTable);

                startActivityForResult(customIntent, 1);
            }
        });



    }



    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        try {
            if((requestCode == 1)&&(resultCode == Activity.RESULT_OK)){
                Bundle myResultBundle = data.getExtras();
                albumStudentName.setText(myResultBundle.getString("name"));
            }
        }
        catch (Exception e) {
            //
        }

    };



}

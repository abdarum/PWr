    package com.example.a235420_ks_a4;

import android.app.Activity;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

    public class CustomActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_custom);

        TextView albumIdx = findViewById(R.id.textView);
        final EditText studentName = findViewById(R.id.editText);
        Button button = findViewById(R.id.button);

        final Intent myLocalIntent = getIntent();
        final Bundle myBundle = myLocalIntent.getExtras();
        albumIdx.setText(myBundle.getString("idx"));

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                myBundle.putString("name", studentName.getText().toString());
                myLocalIntent.putExtras(myBundle);
                setResult(Activity.RESULT_OK, myLocalIntent);
                finish();
            }
        });

    }
}

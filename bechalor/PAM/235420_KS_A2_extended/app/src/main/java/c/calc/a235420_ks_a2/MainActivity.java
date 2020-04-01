package c.calc.a235420_ks_a2;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.inputmethod.EditorInfo;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {


    Button buttonCalculate;
    EditText editTextValue;
    EditText editTextOutput;
    RadioGroup radioGroupService;
    RadioButton radioButtonServiceExcelent;
    RadioButton radioButtonServiceGood;
    RadioButton radioButtonServiceBad;
    RadioGroup radioGroupFood;
    RadioButton radioButtonFoodDelicious;
    RadioButton radioButtonFoodGood;
    RadioButton radioButtonFoodBad;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final double TIPPART = 0.1;

        radioGroupService = findViewById(R.id.radioGroupService);
        radioButtonServiceExcelent = findViewById(R.id.radioButtonServiceExcelent);
        radioButtonServiceGood = findViewById(R.id.radioButtonServiceGood);
        radioButtonServiceBad = findViewById(R.id.radioButtonServiceBad);

        radioGroupFood =  findViewById(R.id.radioGroupFood);
        radioButtonFoodDelicious = findViewById(R.id.radioButtonFoodDelicious);
        radioButtonFoodGood = findViewById(R.id.radioButtonFoodGood);
        radioButtonFoodBad = findViewById(R.id.radioButtonFoodBad);

        editTextValue = findViewById(R.id.editTextValue);
        editTextValue.setInputType(EditorInfo.TYPE_NUMBER_FLAG_DECIMAL);
        editTextOutput = findViewById(R.id.editTextOutput);
        editTextOutput.setInputType(EditorInfo.TYPE_NULL);

        buttonCalculate = findViewById(R.id.buttonCalculate);
        buttonCalculate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    Double dishValue = 0.0;
                    dishValue = Double.parseDouble(editTextValue.getText().toString());
                    dishValue = dishValue * (TIPPART);

                    int radioServiceId = radioGroupService.getCheckedRadioButtonId();
                    int radioFoodId = radioGroupFood.getCheckedRadioButtonId();

                    if (radioFoodId == R.id.radioButtonFoodDelicious) {
                        dishValue = dishValue*1.5;
                    } else if (radioFoodId == R.id.radioButtonFoodBad) {
                        dishValue = dishValue*0.5;
                    }

                    if (radioServiceId == R.id.radioButtonServiceExcelent) {
                        dishValue = dishValue * 1.5;
                    } else if (radioServiceId == R.id.radioButtonServiceBad) {
                        dishValue = dishValue*0.5;
                    }

                    editTextOutput.setText(String.format("%.2g", dishValue));
                }
                catch(Exception e) {
                    Toast.makeText(MainActivity.this, "Enter correct value of dish", Toast.LENGTH_SHORT).show();
                }

            }
        });
    }
}

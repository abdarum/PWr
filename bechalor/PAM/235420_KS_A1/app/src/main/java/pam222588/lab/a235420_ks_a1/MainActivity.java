package pam222588.lab.a235420_ks_a1;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toast.makeText(this, "Stworzono(onCreate)", 0).show();
    }

    @Override
    protected void onStart() {
        super.onStart();
        Toast.makeText(this, "Wystartowano(onStart)",0).show();
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Toast.makeText(this, "Zrestartowano(onRestart)",0).show();
    }

    @Override
    protected void onPostResume() {
        super.onPostResume();
        Toast.makeText(this, "Odtworzono(onResume)",0).show();
    }

    @Override
    protected void onStop() {
        super.onStop();
        Toast.makeText(this, "Zatrzymano(onStop)",0).show();
    }

    @Override
    protected void onPause() {
        super.onPause();
        Toast.makeText(this, "Zpauzowano(onPause)",0).show();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Toast.makeText(this, "Zniszczono(onDestroy)",0).show();
    }
}

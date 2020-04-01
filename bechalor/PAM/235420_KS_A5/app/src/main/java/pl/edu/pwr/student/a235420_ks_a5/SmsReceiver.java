package pl.edu.pwr.student.a235420_ks_a5;


import android.annotation.TargetApi;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.telephony.SmsMessage;
import android.util.Log;
import android.widget.Toast;

public class SmsReceiver extends BroadcastReceiver {
    private static final String SMS_REC_ACTION =
            "android.provider.Telephony.SMS_RECEIVED";


    @Override
    public void onReceive(Context context, Intent intent) {
        Log.e("MY_SMS_RECIVER", "Recived Broadcast");
        if (intent.getAction().
                equals(SmsReceiver.SMS_REC_ACTION)) {

            Log.e("MY_SMS_RECIVER", "Recived SMS");

            StringBuilder sb = new StringBuilder();
            Bundle bundle = intent.getExtras();
            if (bundle != null) {
                Object[] pdus = (Object[])
                        bundle.get("pdus");
                for (Object pdu : pdus) {
                    SmsMessage smsMessage =
                            SmsMessage.createFromPdu
                                    ((byte[]) pdu);
                    sb.append("body - " + smsMessage.
                            getDisplayMessageBody());
                }
            }
            Toast.makeText(context, "SMS RECEIVED - "
                    + sb.toString(), Toast.LENGTH_LONG).show();
        }


    }
}

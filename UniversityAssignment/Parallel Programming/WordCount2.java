import java.io.IOException;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class WordCount2 {
    public static class ItemFreq {
        private String item;
        private Long freq;
        public ItemFreq() {
          this.item = "";
          this.freq = 0L;
        }

        public ItemFreq(String item, long freq) {
           this.item = item;
           this.freq = freq;

        }
        public String getItem() {
           return item;
        }
        public void setItem(String item) {
            this.item = item;
        }
        public Long getFreq() {
            return freq;
        }
        public void setFreq(Long freq) {
            this.freq = freq;
        }
    }
    public static void insert(PriorityQueue<ItemFreq> queue, String item, Long Value) {
        ItemFreq itemFreq = new ItemFreq(item, Value);
        queue.add(itemFreq);
    }
    
    public static class ItemFreqComparator implements Comparator<ItemFreq> {
        public int compare(ItemFreq o1, ItemFreq o2) {
            if (o1.getFreq() > o2.getFreq()) {
                return -1;
            }
            if (o1.getFreq() < o2.getFreq()) {
                return 1;
            }
        return 0;
        }
    }

    public static class TokenizerMapper extends Mapper<Object, Text, Text, LongWritable> {
         private final static LongWritable one = new LongWritable(1);
         private Text word = new Text();
        public void map(Object key, Text value, Context context) throws IOException, InterruptedException {
              StringTokenizer itr = new StringTokenizer(value.toString());
              while (itr.hasMoreTokens()) {
                word.set(itr.nextToken());
                context.write(word, one);
              }
         }
    } 
    public static class IntSumReducer extends Reducer<Text, LongWritable, Text, LongWritable> {
        Comparator<ItemFreq> comparator = new ItemFreqComparator();
        PriorityQueue<ItemFreq> queue = new PriorityQueue<ItemFreq>(comparator);
       
        public void reduce(Text key, Iterable<LongWritable> values, Context context) throws IOException, InterruptedException {
            long sum = 0;
            for (LongWritable val : values) {
                sum += val.get();
            }
            insert(queue, key.toString(), sum);
        }

        protected void cleanup(Context context) throws IOException, InterruptedException {
            while (queue.size() != 0) {
                ItemFreq item = queue.remove();
                context.write(new Text(item.getItem()), new LongWritable(item.getFreq()));
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, "word count");
        job.setJarByClass(WordCount2.class);
        job.setMapperClass(TokenizerMapper.class);
        job.setReducerClass(IntSumReducer.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(LongWritable.class);
        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }      
}  
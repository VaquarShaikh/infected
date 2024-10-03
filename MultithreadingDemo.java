import java.util.concurrent.*;
import java.lang.Thread;

class SharedResource {
	private int value = 0;
	private boolean valueSet = false;

	public synchronized void produce(int newValue) throws InterruptedException {
		while (valueSet) {
			wait();
		}
		value = newValue;
		valueSet = true;
		System.out.println("Produced: " + value);
		notify();
	}

	public synchronized int consume() throws InterruptedException {
		while (!valueSet) {
			wait();
		}
		valueSet = false;
		System.out.println("Consumed: " + value);
		notify();
		return value;
	}
}

class Producer implements Runnable {
	private SharedResource resource;

	public Producer(SharedResource resource) {
		this.resource = resource;
	}

	@Override
	public void run() {
		for (int i = 0; i < 5; i++) {
			try {
				resource.produce(i);
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				Thread.currentThread().interrupt();
			}
		}
	}
}

class Consumer implements Runnable {
	private SharedResource resource;

	public Consumer(SharedResource resource) {
		this.resource = resource;
	}

	@Override
	public void run() {
		for (int i = 0; i < 5; i++) {
			try {
				// int value = resource.consume();
				resource.consume();
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				Thread.currentThread().interrupt();
			}
		}
	}
}

class Counter extends Thread {
	private int count = 0;

	@Override
	public void run() {
		for (int i = 0; i < 5; i++) {
			count++;
			System.out.println(Thread.currentThread().getName() + " Count: " + count);
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				Thread.currentThread().interrupt();
			}
		}
	}
}

public class MultithreadingDemo {
	public static void main(String[] args) throws InterruptedException {
		// 1. Creating threads by implementing Runnable
		SharedResource resource = new SharedResource();
		Thread producerThread = new Thread(new Producer(resource), "Producer");
		Thread consumerThread = new Thread(new Consumer(resource), "Consumer");

		producerThread.start();
		consumerThread.start();

		producerThread.join();
		consumerThread.join();

		System.out.println("Producer-Consumer finished");

		// 2. Creating threads by extending Thread class
		Counter counter1 = new Counter();
		Counter counter2 = new Counter();

		counter1.setName("Counter1");
		counter2.setName("Counter2");

		counter1.start();
		counter2.start();

		counter1.join();
		counter2.join();

		System.out.println("Counters finished");

		// 3. Using ExecutorService for thread pool
		ExecutorService executor = Executors.newFixedThreadPool(2);

		for (int i = 0; i < 5; i++) {
			final int taskId = i;
			executor.submit(() -> {
				System.out.println("Task " + taskId + " executed by " + Thread.currentThread().getName());
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					Thread.currentThread().interrupt();
				}
			});
		}

		executor.shutdown();
		executor.awaitTermination(1, TimeUnit.MINUTES);

		System.out.println("All tasks completed");
	}
}
import time

def measure_time(func):
	def wrapper(*args , **kwargs):
		start_time = time.time()
		result = func(*args , **kwargs)
		end_time = time.time()
		elapsed_time = end_time - start_time
		print(f"Function {func.__name__} took {elapsed_time:.4f} seconds to execute")
		return result
	return wrapper

@measure_time
def some_function(n):
	time.sleep(n)
	return f"Operation completed after {n} seconds ."

print(some_function(5))
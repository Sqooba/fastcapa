

void fill_array(int until, int result[]) {
    for(int i = 0; i < until; i++) {
        result[i] = i;
    }
}

int check_args(int rx_queues_count, int kafka_partitions_count, int result[]) {
    int req_size;
    int size = sizeof(result)/sizeof(result[0]);

    // 1 rx queue: array must hold all partition ids.
    if(rx_queues_count == 1 && size == kafka_partitions_count) {
        return 0;
    }

    // multiple rx queues: check it's a multiple of 2, and it is a divider of the partition count.
    req_size = kafka_partitions_count/rx_queues_count;
    if(rx_queues_count % 2 == 0 && kafka_partitions_count % rx_queues_count == 0 && req_size == size) {
        return 0;
    }

    // Something is wrong.
    return 1;
}

int kafka_partitions_for_queue(int rx_queue_id, int rx_queues_count, int kafka_partitions_count, int result[]) {

    if(!check_args(rx_queues_count, kafka_partitions_count, result)) {
        return -1;
    }

    int i = 0;
    int p_id = rx_queue_id;

    while(p_id < kafka_partitions_count) {
        result[i] = p_id;
        p_id += rx_queues_count;
        i++;
    }

    return i;
}
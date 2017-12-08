

#ifndef FASTCAPA_PARTITION_H
#define FASTCAPA_PARTITION_H

#endif //FASTCAPA_PARTITION_H

/**
 * Determine which kafka partitions belong to a specific RX queue.
 *
 * The number of partitions must be a multiple of the number of rx queues, which must be a multiple of 2.
 *
 * The only exception is if there is only a single rx queue. In this case, all partitions will be attributed
 * to it.
 *
 * @param rx_queue_id index of the queue for which the partitions must be determined
 * @param rx_queues_count total number of rx queues
 * @param kafka_partitions_count total number of kafka partitions
 * @param attributed_partitions where the partition id's will be written.
 * @return the number of partitions added to 'attributed_partitions'. Must have size kafka_partitions_count/rx_queues_count
 */
int kafka_partitions_for_queue(
        int rx_queue_id,
        int rx_queues_count,
        int kafka_partitions_count,
        int attributed_partitions[]);